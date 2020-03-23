package com.example.android.lifecycleweather;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.ViewModel;

import com.example.android.lifecycleweather.data.ForecastItem;
import com.example.android.lifecycleweather.data.Status;
import com.example.android.lifecycleweather.data.weatherRepository;

import java.util.List;

public class weatherViewModel extends ViewModel {
    private LiveData<List<ForecastItem>> mSearchResults;
    private weatherRepository mRepository;
    private LiveData<Status> mLoadingStatus;

    public weatherViewModel() {
        mRepository = new weatherRepository();
        mSearchResults = mRepository.getSearchResults();
        mLoadingStatus = mRepository.getLoadingStatus();
    }

    public void loadSearchResults(String query1, String query2) {
        mRepository.loadSearchResults(query1, query2);
    }

    public LiveData<List<ForecastItem>> getSearchResults() {
        return mSearchResults;
    }

    public LiveData<Status> getLoadingStatus() {
        return mLoadingStatus;
    }
}
