package com.example.android.sqliteweather.data;

import android.app.Application;
import android.os.AsyncTask;

import androidx.lifecycle.LiveData;

import java.util.List;

public class SavedReposRepository {
    private SavedLocationsDao mSavedLocationsDao;

    public SavedReposRepository(Application application) {
        AppDatabase db = AppDatabase.getDatabase(application);
        mSavedLocationsDao = db.savedLocationsDao();
    }

    public void insertLocation(LocationHolder location){
        new InsertAsyncTask(mSavedLocationsDao).execute(location);
    }

    public void deleteLocation(LocationHolder location){
        new DeleteAsyncTask(mSavedLocationsDao).execute(location);
    }

    public LiveData<List<LocationHolder>> getmLocationHolders() {
        return mSavedLocationsDao.getAllRepos();
    }

    private static class InsertAsyncTask extends AsyncTask<LocationHolder, Void, Void> {
        private SavedLocationsDao mAsyncTaskDao;

        InsertAsyncTask(SavedLocationsDao dao) {
            mAsyncTaskDao = dao;
        }


        @Override
        protected Void doInBackground(LocationHolder... LocationHolders) {
            mAsyncTaskDao.insert(LocationHolders[0]);
            return null;
        }
    }

    private static class DeleteAsyncTask extends AsyncTask<LocationHolder, Void, Void> {
        private SavedLocationsDao mAsyncTaskDao;

        DeleteAsyncTask(SavedLocationsDao dao) {
            mAsyncTaskDao = dao;
        }


        @Override
        protected Void doInBackground(LocationHolder... LocationHolders) {
            mAsyncTaskDao.delete(LocationHolders[0]);
            return null;
        }
    }
}
