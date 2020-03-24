package com.example.android.lifecycleweather;

import android.content.Intent;
import android.content.SharedPreferences;
import android.location.Location;
import android.net.Uri;
import android.os.AsyncTask;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.preference.PreferenceManager;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.text.TextUtils;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.example.android.lifecycleweather.data.ForecastItem;
import com.example.android.lifecycleweather.data.Status;
import com.example.android.lifecycleweather.data.WeatherPreferences;
import com.example.android.lifecycleweather.data.weatherRepository;
import com.example.android.lifecycleweather.utils.NetworkUtils;
import com.example.android.lifecycleweather.utils.OpenWeatherMapUtils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity implements ForecastAdapter.OnForecastItemClickListener {

    private static final String TAG = MainActivity.class.getSimpleName();
    private static final String WEATHER_KEY = "weatherKey";
    private String forecastLocation = WeatherPreferences.getDefaultForecastLocation();
    private String tempUnit = WeatherPreferences.getDefaultTemperatureUnits();
    private ArrayList<ForecastItem> mForecastList;

    private TextView mForecastLocationTV;
    private RecyclerView mForecastItemsRV;
    private ProgressBar mLoadingIndicatorPB;
    private TextView mLoadingErrorMessageTV;
    private ForecastAdapter mForecastAdapter;

    private weatherViewModel mWeatherViewModel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mForecastList = null;

        // Remove shadow under action bar.
        getSupportActionBar().setElevation(0);

        mForecastLocationTV = findViewById(R.id.tv_forecast_location);
        Log.d(TAG, "after the setText: " + mForecastLocationTV.getText());

        mLoadingIndicatorPB = findViewById(R.id.pb_loading_indicator);
        mLoadingErrorMessageTV = findViewById(R.id.tv_loading_error_message);
        mForecastItemsRV = findViewById(R.id.rv_forecast_items);

        mForecastAdapter = new ForecastAdapter(this);
        mForecastItemsRV.setAdapter(mForecastAdapter);
        mForecastItemsRV.setLayoutManager(new LinearLayoutManager(this));
        mForecastItemsRV.setHasFixedSize(true);

        mWeatherViewModel = new ViewModelProvider(this).get(weatherViewModel.class);

        mWeatherViewModel.getSearchResults().observe(this, new Observer<List<ForecastItem>>() {
            @Override
            public void onChanged(List<ForecastItem> forecastItems) {
                mForecastAdapter.updateForecastItems((ArrayList<ForecastItem>) forecastItems);
            }
        });

        mWeatherViewModel.getLoadingStatus().observe(this, new Observer<Status>() {
            @Override
            public void onChanged(Status status) {
                if (status == Status.LOADING) {
                    mLoadingIndicatorPB.setVisibility(View.VISIBLE);
                } else if (status == Status.SUCCESS) {
                    mLoadingIndicatorPB.setVisibility(View.INVISIBLE);
                    mForecastItemsRV.setVisibility(View.VISIBLE);
                    mLoadingErrorMessageTV.setVisibility(View.INVISIBLE);
                } else {
                    mLoadingIndicatorPB.setVisibility(View.INVISIBLE);
                    mForecastItemsRV.setVisibility(View.INVISIBLE);
                    mLoadingErrorMessageTV.setVisibility(View.VISIBLE);
                }
            }
        });

//        if (savedInstanceState != null &&
//                savedInstanceState.containsKey(WEATHER_KEY)) {
//            mForecastList = (ArrayList)savedInstanceState.getSerializable(WEATHER_KEY);
//            mForecastAdapter.updateForecastItems(mForecastList);
//        }


        loadForecast(forecastLocation, tempUnit);
        mForecastLocationTV.setText(weatherRepository.locationGetter());

    }

//    @Override
//    protected void onSaveInstanceState(Bundle outState) {
//        super.onSaveInstanceState(outState);
//        if (mForecastList != null) {
//            outState.putSerializable(WEATHER_KEY,
//                    mForecastList);
//        }
//    }


    public boolean shouldChange(String query1, String query2) {
        if (!TextUtils.equals(forecastLocation, query1) || !TextUtils.equals(tempUnit, query2)) {
            return true;
        }else {
            return false;
        }
    }

    @Override
    public void onForecastItemClick(ForecastItem forecastItem) {
        Intent intent = new Intent(this, ForecastItemDetailActivity.class);
        intent.putExtra(OpenWeatherMapUtils.EXTRA_FORECAST_ITEM, forecastItem);
        startActivity(intent);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.action_location:
                showForecastLocation();
                return true;
            case R.id.action_settings:
                Intent intent = new Intent(this, settingsActivity.class);
                startActivity(intent);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    public void loadForecast(String query1, String query2) {
        if (shouldChange(query1, query2)) {
            forecastLocation = query1;
            tempUnit = query2;
            SharedPreferences sharedPreferences =
                    PreferenceManager.getDefaultSharedPreferences(this);
            String location = sharedPreferences.getString(getString(R.string.pref_location_key), query1);
            String sort = sharedPreferences.getString(
                    getString(R.string.pref_sort_key), query2);

            mWeatherViewModel.loadSearchResults(sort, location);
        } else {
            SharedPreferences sharedPreferences =
                    PreferenceManager.getDefaultSharedPreferences(this);
            String location = sharedPreferences.getString(getString(R.string.pref_location_key), "");
            String sort = sharedPreferences.getString(
                    getString(R.string.pref_sort_key), getString(R.string.pref_sort_default));

            mWeatherViewModel.loadSearchResults(sort, location);
        }

    }

    public void showForecastLocation() {
        Uri geoUri = Uri.parse("geo:0,0").buildUpon()
                .appendQueryParameter("q", weatherRepository.locationGetter())
                .build();
        Intent mapIntent = new Intent(Intent.ACTION_VIEW, geoUri);
        if (mapIntent.resolveActivity(getPackageManager()) != null) {
            startActivity(mapIntent);
        }
    }

    class OpenWeatherMapForecastTask extends AsyncTask<String, Void, String> {
        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            mLoadingIndicatorPB.setVisibility(View.VISIBLE);
        }

        @Override
        protected String doInBackground(String... params) {
            String openWeatherMapURL = params[0];
            String forecastJSON = null;
            try {
                forecastJSON = NetworkUtils.doHTTPGet(openWeatherMapURL);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return forecastJSON;
        }

        @Override
        protected void onPostExecute(String forecastJSON) {
            mLoadingIndicatorPB.setVisibility(View.INVISIBLE);
            if (forecastJSON != null) {
                mLoadingErrorMessageTV.setVisibility(View.INVISIBLE);
                mForecastItemsRV.setVisibility(View.VISIBLE);
                mForecastList = OpenWeatherMapUtils.parseForecastJSON(forecastJSON);
                mForecastAdapter.updateForecastItems(mForecastList);
            } else {
                mForecastItemsRV.setVisibility(View.INVISIBLE);
                mLoadingErrorMessageTV.setVisibility(View.VISIBLE);
            }
        }
    }
}
