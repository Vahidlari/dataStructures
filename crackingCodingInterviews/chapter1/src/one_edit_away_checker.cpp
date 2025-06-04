#include "chapter1/one_edit_away_checker.hpp"

bool isOneEditAway_usingLengthComparison(const std::string& str1, const std::string& str2){
    bool isOneAway = false;
    if(str1.length() == str2.length()){
        // Only a replace could be one away
        uint8_t numberOfDiff = 0; 
        isOneAway = true;
        for(std::size_t i = 0; i < str1.length(); i++){
            if(str1[i] != str2[i]){
                if (numberOfDiff >= 1) {
                    isOneAway = false;
                    break;
                } else {
                    // We can continue checking the rest of the string
                    // as we only need to find one difference
                    numberOfDiff++;
                }
            }
        }
    } else if (abs(str1.length() - str2.length()) == 1){
        // Either remove or insert
        uint8_t numberOfDiff = 0;
        bool str1Smaller = (str1.length() < str2.length());
        int smallerLength = str1Smaller? str1.length() : str2.length();
        int str1Index = 0, str2Index = 0;
        isOneAway = true;
        while (str1Index < smallerLength && str2Index < smallerLength && isOneAway){
            if(str1[str1Index] == str2[str2Index]) {
                str1Index++;
                str2Index++;
            } else {
                numberOfDiff++;
                if(numberOfDiff > 1){
                    isOneAway = false;
                } else {
                    str1Index = (!str1Smaller)? str1Index + 1: str1Index;
                    str2Index = (str1Smaller)? str2Index + 1: str2Index;
                }
            }
        }
    } else {
        isOneAway = false;
    }

    return isOneAway;
}