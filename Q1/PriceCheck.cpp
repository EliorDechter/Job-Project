#include <vector>
#include <map>

using namespace std;

bool check_for_wrong_input(vector<string> &products, vector<float> &product_prices, vector<string> &products_sold, vector<float> &sold_prices) {
    bool error = false;
    
    if (products.size() != product_prices.size()) {
        fprintf(stderr, "number of products must be equal to the number of product prices\n");
        error = true;
    }
    if (products_sold.size() != sold_prices.size()) {
        fprintf(stderr, "number of products must be equal to the number of product prices\n");
        error = true;
    }
    if (products.size() > 99 || products.size() < 1) {
        fprintf(stderr, "number of products must be between 1 and 99\n");
        error = true;
    }
    if (product_prices.size() > 99 || product_prices.size() < 1) {
        fprintf(stderr, "number of products must be between 1 and 99\n");
        error = true;
    }
    if (products_sold.size() > 99 || products_sold.size() < 1) {
        fprintf(stderr, "number of products sold must be between 1 and 99\n");
        error = true;
    }
    if (sold_prices.size() > 99 || sold_prices.size() < 1) {
        fprintf(stderr, "number of sold prices must be between 1 and 99\n");
        error = true;
    }
    
    for (size_t i = 0; i < product_prices.size(); ++i) {
        if (product_prices[i] > 100000 || product_prices[i] < 1) {
            fprintf(stderr, "product price %zu must be between 1 and 100000\n", i);
            error = true;
        }
    }
    
    for (size_t i = 0; i < sold_prices.size(); ++i) {
        if (sold_prices[i] > 100000 || sold_prices[i] < 1) {
            fprintf(stderr, "sold price %zu must be between 1 and 100000\n", i);
            error = true;
        }
    }
    
    return error;
}

int price_check(vector<string> &products, vector<float> &product_prices, vector<string> &products_sold, vector<float> &sold_prices) {
    //hash all the products
    map<string, float> products_map;
    
    for (size_t i = 0; i < products.size(); ++i) {
        products_map[products[i]] = product_prices[i];
    }
    
    //search for errors
    int counter = 0;
    for (size_t i = 0; i < products_sold.size(); ++i) {
        if (sold_prices[i] != products_map[products_sold[i]])
            counter++;
    }
    
    return counter;
}

int main() {
    vector<string> products { "rice", "sugar", "wheat", "cheese" };
    vector<float> product_prices { 16.89, 56.92, 20.89, 345.99 };
    vector<string> products_sold {"rice", "cheese" };
    vector<float> sold_price { 18.99, 400.89 };
    
    bool wrong_input  = check_for_wrong_input(products, product_prices, products_sold, sold_price);
    if (!wrong_input)
        return 1;
    int result = price_check(products, product_prices, products_sold, sold_price);
    printf("%d\n", result);
    
    return 0;
}