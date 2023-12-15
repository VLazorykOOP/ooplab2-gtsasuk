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

/*������� ����� ����� �� �������, ������ 8, �������� �������� �� ���� ���� ��
��������� ������: ��� �� ������� ����� �����������, �� ����� ��� ������ ������
�����, ��� �� ������� � ����� ��� ������ ������ ����� � �.�. ��� ������ ������ �����
������ �����������.*/