package com.example.android.connectedweather;

import androidx.recyclerview.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.ArrayList;
import com.example.android.connectedweather.data.storeForecast;



public class ForecastAdapter extends RecyclerView.Adapter<ForecastAdapter.ForecastItemViewHolder> {

    private ArrayList<storeForecast> mForecastData;
    private ArrayList<storeForecast> mDetailedForecastData;
    private OnForecastItemClickListener mOnForecastItemClickListener;

    public ForecastAdapter(OnForecastItemClickListener onForecastItemClickListener) {
        mOnForecastItemClickListener = onForecastItemClickListener;
    }

    public void updateForecastData(ArrayList<storeForecast> forecastData, ArrayList<storeForecast> detailedForecastData) {
        mForecastData = forecastData;
        mDetailedForecastData = detailedForecastData;
        notifyDataSetChanged();
    }

    @Override
    public int getItemCount() {
        if (mForecastData != null && mDetailedForecastData != null) {
            return Math.min(mForecastData.size(), mDetailedForecastData.size());
        } else {
            return 0;
        }
    }

    @Override
    public ForecastItemViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View view = inflater.inflate(R.layout.forecast_list_item, parent, false);
        return new ForecastItemViewHolder(view);
    }

    @Override
    public void onBindViewHolder(ForecastItemViewHolder holder, int position) {
        holder.bind(mForecastData.get(position));
    }

    public interface OnForecastItemClickListener {
        void onForecastItemClick(storeForecast detailedForecast);
    }

    class ForecastItemViewHolder extends RecyclerView.ViewHolder {
        private TextView mForecastTextView;

        public ForecastItemViewHolder(View itemView) {
            super(itemView);
            mForecastTextView = itemView.findViewById(R.id.tv_forecast_text);

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    //ArrayList<storeForecast> detailedForecast = mDetailedForecastData.get(getAdapterPosition());
                    mOnForecastItemClickListener.onForecastItemClick(mForecastData.get(getAdapterPosition()));
                }
            });
        }

        public void bind(storeForecast forecast) {
            mForecastTextView.setText(forecast.dt_txt + " - " + forecast.weather.get(0).main + " - " + (Math.round((forecast.main.temp-273)*100.00))/100.00  + "C");
        }
    }
}
