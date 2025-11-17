#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

class BigInt {
private:
    vector<int> digits;

public:
    BigInt() : digits({0}) {}

    BigInt(const string& s) {
        if (s.empty() || s == "0") {
            digits = {0};
            return;
        }
        for (int i = s.length() - 1; i >= 0; --i) {
            digits.push_back(s[i] - '0');
        }
    }

    BigInt(long long n) {
        if (n == 0) {
            digits = {0};
            return;
        }
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    BigInt operator*(long long k) const {
        BigInt result;
        result.digits.clear(); 

        long long carry = 0;
        for (int digit : digits) {
            
            long long product = (long long)digit * k + carry; 
            
            result.digits.push_back(product % 10); 
            carry = product / 10; 
        }

        while (carry > 0) {
            result.digits.push_back(carry % 10);
            carry /= 10;
        }

        if (result.digits.empty()) {
            result.digits.push_back(0);
        }
        return result;
    }

    /**
     * @brief 거듭제곱을 계산합니다. (31^50)
     */
    static BigInt power(long long base, int exponent) {
        BigInt result(1LL); 

        for (int i = 0; i < exponent; ++i) {
            
            result = result * base; 
        }
        return result;
    }

    string toString() const {
        string s;
        for (int digit : digits) {
            s += to_string(digit);
        }
        
        reverse(s.begin(), s.end());
        return s;
    }

    BigInt operator+(const BigInt& other) const {
        BigInt result;
        result.digits.clear();

        int carry = 0;
        size_t len1 = digits.size();
        size_t len2 = other.digits.size();
        size_t max_len = max(len1, len2);

        for (size_t i = 0; i < max_len || carry; ++i) {
            int d1 = (i < len1) ? digits[i] : 0;
            int d2 = (i < len2) ? other.digits[i] : 0;

            int sum = d1 + d2 + carry;
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        
        
        if (result.digits.empty()) {
            result.digits.push_back(0);
        }
        return result;
    }
    
    BigInt operator*(const BigInt& other) const {
        BigInt final_result("0");

        for (size_t i = 0; i < other.digits.size(); ++i) {
            int digit = other.digits[i]; 

            
            BigInt partial_product = (*this) * (long long)digit;

            
            if (partial_product.digits.size() == 1 && partial_product.digits[0] == 0) {
                
            } else {
                for (size_t j = 0; j < i; ++j) {
                    partial_product.digits.insert(partial_product.digits.begin(), 0);
                }
            }
            
            
            final_result = final_result + partial_product;
        }

        return final_result;
    }
};

int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    BigInt total("0");
    for(int i=0;i<n;i++){
        int x = s[i]-'a' +1;
        BigInt powerVal = BigInt::power(31, i);
        BigInt multVal = powerVal * x;
        
        total = total + multVal;
    }
    cout << total.toString() << endl;
    return 0;
}