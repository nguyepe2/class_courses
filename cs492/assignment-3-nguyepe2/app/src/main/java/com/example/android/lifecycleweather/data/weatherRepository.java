package com.example.android.lifecycleweather.data;

import android.text.TextUtils;
import android.util.Log;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import com.example.android.lifecycleweather.utils.OpenWeatherMapUtils;

import java.util.List;

public class weatherRepository implements weatherAsyncTask.Callback {
    private static final String TAG = weatherRepository.class.getSimpleName();
    private MutableLiveData<List<ForecastItem>> mSearchResults;
    private MutableLiveData<Status> mLoadingStatus;
    private static String mCurrentQuery = WeatherPreferences.getDefaultTemperatureUnitsAbbr();
    private static String mCurrentQuery2 = WeatherPreferences.getDefaultForecastLocation();



    public weatherRepository() {
        mSearchResults = new MutableLiveData<>();
        mSearchResults.setValue(null);

        mLoadingStatus = new MutableLiveData<>();
        mLoadingStatus.setValue(Status.SUCCESS);

        mCurrentQuery = null;
    }

    public LiveData<List<ForecastItem>> getSearchResults() {
        return mSearchResults;
    }

    public LiveData<Status> getLoadingStatus() {
        return mLoadingStatus;
    }

    private boolean shouldExecuteSearch(String query1, String query2){
        if (!TextUtils.equals(query1, mCurrentQuery) || !TextUtils.equals(query2, mCurrentQuery2)) {
            return true;
        } else {
            return false;
        }
    }

    public void loadSearchResults(String query1, String query2) {
        if (shouldExecuteSearch(query1, query2)) {
            mCurrentQuery = query1;
            mCurrentQuery2 = query2;
            String url = OpenWeatherMapUtils.buildForecastURL(query1, query2);
            mSearchResults.setValue(null);
            Log.d(TAG, "executing search with url: " + url);

            mLoadingStatus.setValue(Status.LOADING);
            new weatherAsyncTask(url, this).execute();
        } else {
            Log.d(TAG, "using cached results");
        }

    }

    public static String locationGetter() {
        return mCurrentQuery2;
    }

    public static String tempUnitGetter() {
        return mCurrentQuery;
    }

    @Override
    public void onSearchFinished(List<ForecastItem> searchResults) {
        mSearchResults.setValue(searchResults);
        if (searchResults != null) {
            mLoadingStatus.setValue(Status.SUCCESS);
        } else {
            mLoadingStatus.setValue(Status.ERROR);
        }
    }
}
