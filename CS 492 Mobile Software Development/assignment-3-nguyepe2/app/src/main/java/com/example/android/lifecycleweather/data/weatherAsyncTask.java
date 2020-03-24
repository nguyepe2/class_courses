package com.example.android.lifecycleweather.data;

import android.os.AsyncTask;

import com.example.android.lifecycleweather.utils.NetworkUtils;
import com.example.android.lifecycleweather.utils.OpenWeatherMapUtils;

import java.io.IOException;
import java.util.List;

public class weatherAsyncTask extends AsyncTask<Void, Void, String> {
    private String mURL;
    private Callback mCallback;

    public interface Callback {
        void onSearchFinished(List<ForecastItem> searchResults);
    }

    weatherAsyncTask(String url, Callback callback){
        mURL = url;
        mCallback = callback;
    }

    @Override
    protected String doInBackground(Void... voids) {
        String results = null;
        if (mURL != null) {
            try {
                results = NetworkUtils.doHTTPGet(mURL);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return results;
    }


    @Override
    protected void onPostExecute(String s) {
        List<ForecastItem> searchResults = null;
        if (s != null) {
            searchResults =
                    OpenWeatherMapUtils.parseForecastJSON(s);
        }
        mCallback.onSearchFinished(searchResults);
    }


}
