package com.example.android.sqliteweather.data;

import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.Query;

import java.util.List;

@Dao
public interface SavedLocationsDao {
    @Insert(onConflict = OnConflictStrategy.IGNORE)
    void insert(LocationHolder location);

    @Delete
    void delete(LocationHolder location);

    @Query("SELECT * FROM repos")
    LiveData<List<LocationHolder>> getAllRepos();

}
