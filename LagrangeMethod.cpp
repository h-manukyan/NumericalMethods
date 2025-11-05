#include <iostream>
#include <vector>
using namespace std;

// Lagrange interpolation
float L(const vector<float>& in, const vector<float>& out, int n, float x) {
    float res = 0;

    for (int i = 0; i < n; i++) {
        float frac = 1;
        for (int j = 0; j < n; j++) {
            if (i != j)
                frac *= (x - in[j]) / (in[i] - in[j]);
        }
        res += out[i] * frac;
    }
    return res;
}

int main() {
    int n;
    float val;

    cout << "Enter the number of data points: ";
    cin >> n;

    vector<float> x(n), y(n);

    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> y[i];

    cout << "Enter x to interpolate at: ";
    cin >> val;

    cout << "Interpolated value at x = " << val
         << " is: " << L(x, y, n, val) << endl;

    return 0;
}
