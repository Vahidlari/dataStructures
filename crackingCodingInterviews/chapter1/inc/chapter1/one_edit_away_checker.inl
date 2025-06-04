
template <OneEditAwayMethod method>
bool isOneEditAway(const std::string& str1, const std::string& str2) {
    if constexpr (method == OneEditAwayMethod::LengthComparison) {
        return isOneEditAway_usingLengthComparison(str1, str2);
    }
    return false;
}