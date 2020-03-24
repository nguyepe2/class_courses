package com.example.android.connectedweather;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;

import com.example.android.connectedweather.utils.networkUtils;
import com.example.android.connectedweather.utils.weatherUtils;
import com.example.android.connectedweather.data.storeForecast;

public class MainActivity extends AppCompatActivity implements ForecastAdapter.OnForecastItemClickListener {
    private static final String TAG = MainActivity.class.getSimpleName();

    private RecyclerView mForecastListRV;
    private ForecastAdapter mForecastAdapter;
    private Toast mToast;
    private ProgressBar mLoadingIndicatorPB;
    private TextView mErrorMessageTV;


   /* private static final String[] dummyForecastData = {
            "Sunny and Warm - 75F",
            "Partly Cloudy - 72F",
            "Mostly Sunny - 73F",
            "Partly Cloudy - 70F",
            "Occasional Showers - 65F",
            "Showers - 63F",
            "Occasional Showers - 64F",
            "Rainy - 62F",
            "Rainy - 61F",
            "Hurricane - 65F",
            "Windy and Clear - 70F",
            "Sunny and Warm - 77F",
            "Sunny and Warm - 81F"
    }; */

   /* private static final String[] dummyDetailedForecastData = {
            "Not a cloud in the sky today, with lows around 52F and highs near 75F.",
            "Clouds gathering in the late afternoon and slightly cooler than the day before, with lows around 49F and highs around 72F",
            "Scattered clouds all day with lows near 52F and highs near 73F",
            "Increasing cloudiness as the day goes on with some cooling; lows near 48F and highs near 70F",
            "Showers beginning in the morning and popping up intermittently throughout the day; lows near 46F and highs near 65F",
            "Showers scattered throughout the day, with lows near 46F and highs of 63F",
            "Showers increasing in intensity towards evening, with lows near 46F and highs near 64F",
            "Steady rain all day; lows near 47F and highs near 62F",
            "More steady rain, building in intensity towards evening; lows near 47F and highs near 61F",
            "Very, very strong winds and heavy rain; make sure you're wearing your raincoat today; lows near 50F and highs near 65F",
            "Rain ending in the very early morning, then clearing, with residual strong winds; lows near 61F and highs around 70F",
            "Beautiful day, with nothing but sunshine; lows near 55F and highs around 77F",
            "Another gorgeous day; lows near 56F and highs around 81F"
    };*/

   /* @Override
    public void onForecastItemClick(String detailedForecast) {

    }*/

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mForecastListRV = findViewById(R.id.rv_forecast_list);

        mForecastListRV.setLayoutManager(new LinearLayoutManager(this));
        mForecastListRV.setHasFixedSize(true);

        mForecastAdapter = new ForecastAdapter(this);
        mForecastListRV.setAdapter(mForecastAdapter);


        mLoadingIndicatorPB = findViewById(R.id.pb_loading_indicator);
        mErrorMessageTV = findViewById(R.id.tv_error_message);

       /* mForecastAdapter.updateForecastData(
                new ArrayList<String>(Arrays.asList(dummyForecastData)),
                new ArrayList<String>(Arrays.asList(dummyDetailedForecastData))
        );*/
        String fake = "a";
       doWeatherSearch(fake);

      /*  Button searchButton = findViewById(R.id.btn_search);
        searchButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String searchQuery = "fake";
                if (!TextUtils.isEmpty(searchQuery)) {
                    doWeatherSearch(searchQuery);
//                    mGitHubSearchAdapter.updateSearchResults(new ArrayList<String>(Arrays.asList(dummySearchResults)));
                }
            }
        });*/
    }

    private void doWeatherSearch(String query) {
        String url = weatherUtils.buildWeatherSearchURL(query);
        Log.d(TAG, "querying search url: " + url);
        new weatherSearchTask().execute(url);
    }


    public class weatherSearchTask extends AsyncTask<String, Void, String> {

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            mLoadingIndicatorPB.setVisibility(View.VISIBLE);

        }

        @Override
        protected String doInBackground(String... strings) {
            String url = strings[0];
            String results = null;
            try {
                results = networkUtils.doHttpGet(url);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return results;
        }

        /*@Override
        protected void onProgressUpdate(Void... values) {
            super.onProgressUpdate(values);
        }*/

        @Override
        protected void onPostExecute(String s) {
            super.onPostExecute(s);
            mLoadingIndicatorPB.setVisibility(View.INVISIBLE);
            Log.d(TAG, "in post execute" + s);
            if (s != null) {
                mErrorMessageTV.setVisibility(View.INVISIBLE);
                mForecastListRV.setVisibility(View.VISIBLE);
               // ArrayList<String> searchResultsList = new ArrayList<String>();
                //ArrayList<String> useless = new ArrayList<String>();
                //searchResultsList.add(s);
                ArrayList<storeForecast> searchResultsList = weatherUtils.parseWeather(s);
                mForecastAdapter.updateForecastData(searchResultsList, searchResultsList);
                //mSearchBoxET.setText("");

            }
            else {

                mErrorMessageTV.setVisibility(View.VISIBLE);
                mForecastListRV.setVisibility(View.INVISIBLE);
            }
        }
    }

    @Override
    public void onForecastItemClick(storeForecast detailedForecast) {

        Intent intent = new Intent(this, weatherdetailActivity.class);

        Log.d(TAG, "before intent.putExtra");

        intent.putExtra(weatherdetailActivity.EXTRA_WEATHER_INFO, detailedForecast);

        Log.d(TAG, "after intent.putExtra but before startActivity");

        startActivity(intent);

        Log.d(TAG, "After startActivity");
    }

}
