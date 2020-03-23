package com.example.android.sqliteweather;

import android.content.Context;
import android.content.SharedPreferences;
import androidx.preference.PreferenceManager;
import androidx.recyclerview.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.example.android.sqliteweather.data.ForecastItem;
import com.example.android.sqliteweather.utils.OpenWeatherMapUtils;

import java.text.DateFormat;
import java.util.List;

public class ForecastAdapter extends RecyclerView.Adapter<ForecastAdapter.ForecastItemViewHolder> {

    private List<ForecastItem> mForecastItems;
    private OnForecastItemClickListener mForecastItemClickListener;

    public interface OnForecastItemClickListener {
        void onForecastItemClick(ForecastItem forecastItem);
    }

    public ForecastAdapter(OnForecastItemClickListener clickListener) {
        mForecastItemClickListener = clickListener;
    }

    public void updateForecastItems(List<ForecastItem> forecastItems) {
        mForecastItems = forecastItems;
        notifyDataSetChanged();
    }

    @Override
    public int getItemCount() {
        if (mForecastItems != null) {
            return mForecastItems.size();
        } else {
            return 0;
        }
    }

    @Override
    public ForecastItemViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View itemView = inflater.inflate(R.layout.forecast_list_item, parent, false);
        return new ForecastItemViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(ForecastItemViewHolder holder, int position) {
        holder.bind(mForecastItems.get(position));
    }

    class ForecastItemViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        private TextView mForecastDateTV;
        private TextView mForecastTempDescriptionTV;
        private ImageView mWeatherIconIV;

        public ForecastItemViewHolder(View itemView) {
            super(itemView);
            mForecastDateTV = itemView.findViewById(R.id.tv_forecast_date);
            mForecastTempDescriptionTV = itemView.findViewById(R.id.tv_forecast_temp_description);
            mWeatherIconIV = itemView.findViewById(R.id.iv_weather_icon);
            itemView.setOnClickListener(this);
        }

        public void bind(ForecastItem forecastItem) {
            Context context = mForecastDateTV.getContext();
            SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(context);
            String temperatureUnitsValue = sharedPreferences.getString(
                    context.getString(R.string.pref_units_key),
                    context.getString(R.string.pref_units_default_value)
            );
            String temperatureUnitsAbbr = OpenWeatherMapUtils.getTemperatureUnitsAbbr(context, temperatureUnitsValue);

            String dateString = DateFormat.getDateTimeInstance().format(forecastItem.dateTime);
            String detailString = mForecastTempDescriptionTV.getContext().getString(
                    R.string.forecast_item_details, forecastItem.temperature, temperatureUnitsAbbr,
                    forecastItem.description
            );

            mForecastDateTV.setText(dateString);
            mForecastTempDescriptionTV.setText(detailString);

            String iconURL = OpenWeatherMapUtils.buildIconURL(forecastItem.icon);
            Glide.with(mWeatherIconIV.getContext()).load(iconURL).into(mWeatherIconIV);
        }

        @Override
        public void onClick(View v) {
            ForecastItem forecastItem = mForecastItems.get(getAdapterPosition());
            mForecastItemClickListener.onForecastItemClick(forecastItem);
        }
    }
}
