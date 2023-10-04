#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement

    int num_Digit = 0;
    if (digit >= '0' && digit <= '9') {
            num_Digit = (int)digit - 48;      //ASCII     
    }
    else {
        throw std::invalid_argument("Digit not within bounds");
    }
    return num_Digit;

}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement

    char value;

    if (decimal <= 9) {
        value = decimal + '0';
    }
    else {
        throw std::invalid_argument("Digit not within bounds");
    }

    return value;

}

string trim_leading_zeros(string num) {
    // TODO(student): implement

    string str = num;
    int str_size = str.length();
    string final_str = "";

    int i;
    int count = 0;

    for (i = 0; i < str_size; ++i) {
        if (str.at(i) == '-') {
            count++;
            final_str.push_back(str.at(i));
            continue;
        }
        else if (str.at(i) == '0') {
            count ++;
            continue;
        }
        else {
            break;
        }
    }

    for (i = count; i < str_size; ++i) {
        final_str.push_back(str.at(i));
    }
    if (count == str_size || count == str_size + 1) {
        return "0";
    }
    return final_str;

}

string add(string lhs, string rhs) {
    // TODO(student): implement
    string output_val = "";
    
    if(lhs.size() < rhs.size()) {
        swap(lhs, rhs);
    }
    if (lhs == "0") {
        output_val = rhs;
        return output_val;
    } 
    else if (rhs == "0") {
        output_val = lhs;
        return output_val;
    }

    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    bool neg = false;
    bool neg_lhs = false;
    bool neg_rhs = false;

    if(lhs.at(0) == '-' && rhs.at(0) == '-'){

        neg = !neg;
        output_val = '-' + add(lhs.substr(1), rhs.substr(1));
        return output_val;

    }
    else if(lhs.at(0) == '-'){

        neg_lhs = !neg_lhs;

        if((lhs.substr(1).size() == rhs.size()) && (decimal_to_digit(lhs.at(1)) > decimal_to_digit(rhs.at(0)))){

            output_val = '-' + subtract(lhs.substr(1), rhs);
        }
        else if((lhs.substr(1).size() == rhs.size()) && (decimal_to_digit(lhs.at(1)) < decimal_to_digit(rhs.at(1)))){

            output_val = subtract(rhs, lhs.substr(1));
        }
        else if(lhs.substr(1).size() > rhs.size()){

            output_val = '-' + subtract(lhs.substr(1), rhs);
        }
        else if(lhs.substr(1).size() < rhs.size()){

            output_val = subtract(rhs, lhs.substr(1));
        }
        return output_val;

    } else if (rhs.at(0) == '-') {

        neg_rhs = !neg_rhs;

        if((lhs.size() == rhs.substr(1).size()) && (decimal_to_digit(lhs.at(0)) > decimal_to_digit(rhs.at(1)))){

            output_val = '-' + subtract(lhs.substr(1), rhs);
        }
        else if((lhs.size() == rhs.substr(1).size()) && (decimal_to_digit(lhs.at(0)) < decimal_to_digit(rhs.at(1)))){

            output_val = subtract(rhs, lhs.substr(1));
        }
        else if(lhs.substr(1).size() > rhs.size()){

            output_val = '-' + subtract(lhs.substr(1), rhs);
        }
        else if(lhs.substr(1).size() < rhs.size()){

            output_val = subtract(rhs, lhs.substr(1));
        }
        return output_val;
    }

    int lhs_num = 0;
    int rhs_num = 0;
    int remainder = 0;
    int numberSlot = 0;
    int lhs_extra = lhs.size() - rhs.size();
    int i;
    int i_temp;

    for (i_temp = lhs.size(); i_temp > 0; i_temp--)
    {
        i = i_temp - 1;
        lhs_num = digit_to_decimal(lhs.at(i));
        int rhs_i = i - lhs_extra;

        if (rhs_i >= 0) {
            rhs_num = digit_to_decimal(rhs.at(rhs_i));
        }
        else {
            rhs_num = 0;
        }

        numberSlot = lhs_num + rhs_num;
    
        if (remainder > 0) { 
            numberSlot += remainder;
            remainder = 0;
        }
        if (numberSlot >= 10) {
            remainder = (numberSlot / 10) % 10;
            numberSlot = numberSlot % 10;
        }

        if (i == 0 && remainder != 0) {
            output_val = decimal_to_digit(static_cast<char>(numberSlot)) + output_val;
            output_val = decimal_to_digit(static_cast<char>(remainder)) + output_val;
        }
        else {
            output_val = decimal_to_digit(static_cast<char>(numberSlot)) + output_val;
        }
    }
    return output_val;

    

    // return "";
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement

    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    /*bool neg_lhs = false;
    bool neg_rhs = false;
    
    if (lhs.at(0) == '-') {
        neg_lhs = true;
        lhs.erase(0,1);
    }
    if (rhs.at(0) == '-') {
        neg_rhs = true;
        rhs.erase(0,1);
    }

    int max = 0;
    int min = 0;

    string large = "";
    string small = "";

    if (lhs.length() >= rhs.length()) {
        max = lhs.length();
        min = rhs.length();
        small = rhs;
        large = lhs;
    }
    else {
        max = rhs.length();
        min = lhs.length();
        small = lhs;
        large = rhs;
    }

    char s_ary[min];
    char l_ary[max];
    int index = 0;

    for (int i = max - 1; i >= 0; --i) {
        l_ary[index] = large.at(i);
        ++index;
    }

    index = 0;

    for (int i = min - 1; i >= 0; --i) {
        s_ary[index] = small.at(i);
        ++index;
    }

    string num1[min];

    bool carry_digit = false;
    int carry_digit_Value = 0;
    string sum = "";

    int tens = 0;
    int i;
    int j;
    int k;

    for (i = 0; i < min; ++i) {
        for (k = 0; k < tens; ++k) {
            sum += "0";
        }
        for (j = 0; j < max; ++j) {
            int multiply = (digit_to_decimal(s_ary[i])) * (digit_to_decimal(l_ary[j]));
            if (carry_digit) {
                multiply += carry_digit_Value;
            }
            if (multiply >= 10) {
                carry_digit = true;
                carry_digit_Value = multiply / 10;
            }
            else {
                carry_digit = false;
            }
            sum += decimal_to_digit((multiply % 10));
        }
        if (carry_digit) {
            sum += decimal_to_digit(carry_digit_Value);
        }
        num1[i] = sum;
        sum = "";
        carry_digit = false;
        ++tens;
    }
    
    string num_Reverse[min];

    for (int i = 0; i < min; ++i) {
        string sigh = "";
        for (int j = num1[i].length() - 1; j >= 0; --j) {
            sigh += num1[i].substr(j, 1);
        }
        num_Reverse[i] = sigh;
    }
    for (int i = 0; i < min - 1; ++i) {
        string sigh = add(num_Reverse[i], num_Reverse[i + 1]);
        num_Reverse[i + 1] = sigh;
    }
    if (neg_lhs != neg_rhs) {
        string sigh = "-"; 
        sigh += num_Reverse[min - 1];
        return trim_leading_zeros(sigh);
    }
    else {
        return trim_leading_zeros(num_Reverse[min - 1]);
    }
    //return "";
    */

    bool neg = false;

    if (lhs.at(0) == '-') {
          lhs.erase(0, 1);
          neg = true;
    }

    if (rhs.at(0) == '-') {
          rhs.erase(0, 1);
          neg = true;
    }

    int n;
    int m;

    n = lhs.size();
    m = rhs.size();

    if (n == 0) {
        return "0";
    }
    else if (m == 0) {
        return "0";
    }

    string output_value(n + m, '0');
    int i;
    int j;
    int k;

    for (i = n - 1; i >= 0; i--) {
        for (j = m - 1; j >= 0; j--) {
            k = (lhs[i] - '0') * (rhs[j] - '0') + (output_value[i + j + 1] - '0');
            output_value[i + j + 1] = decimal_to_digit(k % 10);
            output_value[i + j] += k / 10;
        }
     }

     output_value = neg ? "-" + output_value : output_value;

     return trim_leading_zeros(output_value);
}



string subtract(string lhs, string rhs) {
    string output_val = "";

    if (lhs == rhs) {
        output_val = "0";
        return output_val;
    }

    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    bool neg_val = false;
    bool neg_lhs = false;
    bool neg_rhs = false;

    if((lhs.at(0) == '-') && (rhs.at(0) == '-')) {

        neg_val = !neg_val;

        if ((lhs.size() == rhs.size()) && (decimal_to_digit(lhs.at(1)) > decimal_to_digit(rhs.at(1)))) {

            output_val = '-' + subtract(lhs.substr(1), rhs.substr(1));
        }
        else if((lhs.size() == rhs.size()) && (decimal_to_digit(lhs.at(1)) < decimal_to_digit(rhs.at(1)))) {

            output_val = subtract(rhs.substr(1), lhs.substr(1));
        }
        else if(lhs.size() > rhs.size()){

            output_val = '-' + subtract(lhs.substr(1), rhs);
        }
        else if(lhs.size() < rhs.size()){

            output_val = '-' + subtract(lhs.substr(1), rhs);
        }

        return output_val;

    }
    
    else if (lhs.at(0) == '-') {

        output_val = '-' + add(lhs.substr(1), rhs);
        neg_lhs = !neg_lhs;

        return output_val;

    }
    else if (rhs.at(0) == '-') {
        output_val = add(lhs, rhs.substr(1));
        neg_rhs = !neg_rhs;

        return output_val;
    }

    int lhs_value = 0;
    int rhs_value = 0;
    int remainder = 0;

    int number_slot = 0;
    int lhs_extra = (lhs.size() - rhs.size());
    bool beta_Remainder = false;

    int i;
    int i_temporary;
    
    for (i_temporary = lhs.size(); i_temporary > 0; i_temporary--) {

        i = i_temporary - 1;

        if (beta_Remainder && digit_to_decimal(lhs.at(i)) >= 1) {
            lhs_value = digit_to_decimal(lhs.at(i)) - remainder;
            beta_Remainder = false;
        }
        else {
            lhs_value = digit_to_decimal(lhs.at(i));
        }

        int rhs_i = i - lhs_extra;

        if (rhs_i >= 0) {
            rhs_value = digit_to_decimal(rhs.at(rhs_i));
        }
        else { 
            rhs_value = 0;
        }

        if ((rhs_i >= 0) && (lhs.at(i) < rhs.at(rhs_i))) {
            beta_Remainder = true;
            remainder += 1;
            number_slot = 10 + lhs_value - rhs_value;
        }
        else {
            number_slot = lhs_value - rhs_value;
        }

        if (remainder > 0) {
            number_slot += remainder;
            remainder = 0;
        }
        if (number_slot >= 10) {
            remainder = (number_slot / 10) % 10;
            number_slot = number_slot % 10;
        }

        if (i == 0 && remainder != 0) {
            output_val = decimal_to_digit(static_cast<char>(number_slot)) + output_val;
            output_val = decimal_to_digit(static_cast<char>(remainder)) + output_val;
        }
        else {

            output_val = decimal_to_digit(static_cast<char>(number_slot)) + output_val;
        }
    }
    if (neg_val) {

        output_val = '-' + output_val;
    }

    return output_val;
}
