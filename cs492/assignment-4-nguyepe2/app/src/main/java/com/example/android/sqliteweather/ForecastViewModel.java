package com.example.android.sqliteweather;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.ViewModel;

import com.example.android.sqliteweather.data.ForecastItem;
import com.example.android.sqliteweather.data.ForecastRepository;
import com.example.android.sqliteweather.data.Status;

import java.util.List;

/*
 * This is the ViewModel class for forecast data.  It manages two different pieces of data: the
 * forecast data itself and a Status value indicating the current network loading status for
 * forecast data.  The ViewModel class uses a Repository class to actually perform data operations.
 */
public class ForecastViewModel extends ViewModel {

    private LiveData<List<ForecastItem>> mForecastItems;
    private LiveData<Status> mLoadingStatus;

    private ForecastRepository mRepository;

    public ForecastViewModel() {
        mRepository = new ForecastRepository();
        mForecastItems = mRepository.getForecast();
        mLoadingStatus = mRepository.getLoadingStatus();
    }

    public void loadForecast(String location, String units) {
        mRepository.loadForecast(location, units);
    }

    public LiveData<List<ForecastItem>> getForecast() {
        return mForecastItems;
    }

    public LiveData<Status> getLoadingStatus() {
        return mLoadingStatus;
    }
}
