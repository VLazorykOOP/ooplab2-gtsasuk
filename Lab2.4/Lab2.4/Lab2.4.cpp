#include <iostream>
#include <vector>

using namespace std;

vector<unsigned char> encodeBytes(const vector<unsigned char>& input) {
    vector<unsigned char> encoded;
    for (size_t i = 0; i < input.size(); i += 8) {
        unsigned char encodingByte = input[i];
        for (size_t j = 0; j < 8; ++j) {
            encoded.push_back((input[i + j] >> (7 - j)) | (encodingByte << j));
        }
    }
    return encoded;
}

int main() {
    vector<unsigned char> input = { 'a','b','c','d','e','f','g','t', 'i'};
    for (; input.size() % 8;) { input.push_back('_'); }
    vector<unsigned char> encoded = encodeBytes(input);
    cout << "Encoded bits array:" << endl;
    for (const auto& byte : encoded) {
        cout << byte << " ";
    }
    cout << endl;

    return 0;
}

/*Вхідний рядок байтів має довжину, кратну 8, написати програму що кодує його за
наступною схемою: вісім біт першого байта записуються, як нулеві біти перших восьми
байтів, вісім біт другого – перші біти других восьми байтів і т.д. для кожних восьми байтів
вхідної послідовності.*/