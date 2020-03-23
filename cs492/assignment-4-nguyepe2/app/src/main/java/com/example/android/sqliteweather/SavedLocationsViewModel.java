package com.example.android.sqliteweather;

import android.app.Application;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;

import com.example.android.sqliteweather.data.LocationHolder;
import com.example.android.sqliteweather.data.SavedReposRepository;

import java.util.List;

public class SavedLocationsViewModel extends AndroidViewModel {
    private LiveData<List<LocationHolder>> mLocationHolders;
    private SavedReposRepository mSavedReposRepository;

    public SavedLocationsViewModel(@NonNull Application application) {
        super(application);
        mSavedReposRepository = new SavedReposRepository(application);
    }

    public void insertLocation(LocationHolder location) {
        mSavedReposRepository.insertLocation(location);
    }

    public void deleteLocation(LocationHolder location) {
        mSavedReposRepository.deleteLocation(location);
    }

    public LiveData<List<LocationHolder>> getmLocationHolders() {
        return mSavedReposRepository.getmLocationHolders();
    }

}
