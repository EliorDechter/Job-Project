#include "a library to make http requests such as curl"
#include "a library to parse the json"

void start_analytics_system(File *file) {
    int refresh_time_in_ms = 60; //ms == miliseconds
    double latest_time = get_time_in_ms();
    
    Rates_queue queue = new Rates_queue(num_frames);
    
    while (1) {
        if (latest_time - get_time_in_ms() >= refresh_time_in_ms) {
            double exchange_rate = parse_json(fetch(request_string));
            if (is_missing_data(file, latest_time)) 
                interpolate_data(file, queue);
            Statistic statistic =
                calculate_exchange_rate_statistic_based_on_five_latest_rates(queue, exchange_rate);
            write_statistic_to_file(statistic, file);
            add_to_rates_queue(exchange_rate);
            latest_time = get_time_in_ms();
        }
    }
}

void main () {
    //assumptions made:
    //The system has been collecting data for a while.
    //The user expects most of the data to be reliable (meaning the machine doesnt crash every
    //second) and the rest of the data can be interpolated based on data collected.
    //We can use linear interpolation to fill in the missing data, and we should check periodicaly if any data
    //is missing due to latency or crash.
    //Many of the operations such as fetch, IO & interpolation should be done asynchronously to
    //avoid  latency
    
    File *file = get_or_create_analytics_file(path_to_file);
    start_analytic_system(file);
}