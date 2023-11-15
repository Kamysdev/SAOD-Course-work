#include "code.hpp"

int up(int n, double q, double* array, double chance[]) {
    int i = 0, j = 0;                 
    for (i = n - 2; i >= 1; i--) {
        if (array[i - 1] < q) array[i] = array[i - 1];
        else {
            j = i;
            break;
        }
        if ((i - 1) == 0 && chance[i - 1] < q) {
            j = 0;
            break;
        }
    }
    array[j] = q;
    return j;
}

void down(int n, int j, int* Length, char** c) {
    char pref[20]{};
    for (int i = 0; i < 20; i++) pref[i] = c[j][i];
    int l = Length[j];
    for (int i = j; i < n - 2; i++) {
        for (int k = 0; k < 20; k++)
            c[i][k] = c[i + 1][k];
        Length[i] = Length[i + 1];
    }
    for (int i = 0; i < 20; i++) {
        c[n - 2][i] = pref[i];
        c[n - 1][i] = pref[i];
    }
    c[n - 1][l] = '1';
    c[n - 2][l] = '0';
    Length[n - 1] = l + 1;
    Length[n - 2] = l + 1;
}

void huffman(int n, double* array, int* Length, char** c, double chance[]) {
    if (n == 2) {
        c[0][0] = '0';
        Length[0] = 1;
        c[1][0] = '1';
        Length[1] = 1;
    }
    else {
        double q = array[n - 2] + array[n - 1];
        int j = up(n, q, array, chance);
        huffman(n - 1, array, Length, c, chance);
        down(n, j, Length, c);
    }
}

std::unordered_map<char, int> get_char_counts_from_file(std::string file_name, int& file_size) {
    const int n = 4000;
    std::ifstream file(file_name, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    char* ch_arr = new char[sizeof(People) * n] {};

    file.read((char*)ch_arr, (std::streamsize)sizeof(People) * n);
    file.close();

    std::unordered_map<char, int> counter_map;
    file_size = 0;

    for (int i = 0; i < sizeof(People) * n; i++)
    {
        counter_map[ch_arr[i]]++;
        file_size++;
    }

    delete[] ch_arr;
    return counter_map;
}

std::vector<std::pair<double, char>> calc_probabilities(const std::unordered_map<char, int>& counter_map, int count) {
    std::vector<std::pair<double, char>> probabilities;
    probabilities.reserve(counter_map.size());
    for (auto &i : counter_map) {
        probabilities.emplace_back(std::make_pair((double)i.second / count, i.first));
    }
    return probabilities;
}

int coding()
{
    system("CLS");

    int file_size;
    std::unordered_map<char, int> counter_map;
    counter_map = get_char_counts_from_file("testBase4.dat", file_size);

    auto probabilities = calc_probabilities(counter_map, file_size);
    counter_map.clear();

    std::sort(probabilities.begin(), probabilities.end(), std::greater<std::pair<double, char>>());
    std::cout << "Probabil.  char\n";
    for (auto &i : probabilities) {
        std::cout << std::fixed << i.first << " | " << i.second << '\n';
    }

    const int n = (int)probabilities.size();

    char** c = new char* [n];
    for (int i = 0; i < n; i++)
    {
        c[i] = new char[20];
    }

    int* Length = new int[n];
    for (int i = 0; i < n; i++)
    {
        Length[i] = 0;
    }

    auto p = new double[n];
    double* chance_l = new double[n];

    for (int i = 0; i < n; ++i) {
        p[i] = probabilities[i].first;
        chance_l[i] = p[i];

    }

    huffman(n, chance_l, Length, c, p);
    std::cout << "\nHaffmanCode:\n";
    std::cout << "\nCh  Prob      Code\n";
    double avg_len = 0;
    double entropy = 0;
    for (int i = 0; i < n; i++) {
        avg_len += Length[i] * p[i];
        entropy -= p[i] * log2(p[i]);
        printf("%c | %.5lf | ", probabilities[i].second, p[i]);
        for (int j = 0; j < Length[i]; ++j) {
            printf("%c", c[i][j]);
        }
        std::cout << '\n';
    }
    std::cout << "Average length = " << avg_len << std::endl
        << "Entropy = " << entropy << std::endl
        << "Average length <" << entropy + 1 << std::endl
        << "N = " << n << std::endl << std::endl;

    system("pause");

    delete[] p;
    delete[] chance_l;
	return 0;
}