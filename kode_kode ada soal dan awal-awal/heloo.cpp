#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

struct point {
    double x, y;
    point() : x(0), y(0) {}
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator==(const point &other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size() - 1)
            left2 = cross(toVec(a, b), toVec(a, Q[i + 1]));
        if (left1 > -EPS)
            P.push_back(Q[i]); // Q[i] is on the left of ab
        if (left1 * left2 < -EPS) // edge crosses line ab
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());
    return P;
}

int main() {
    // Contoh poligon persegi (harus ditutup)
    vector<point> polygon = {
        point(1, 1),
        point(4, 1),
        point(4, 4),
        point(1, 4),
        point(1, 1)
    };

    // Garis pemotong dari (0,2) ke (5,2)
    point a(0, 2), b(5, 2);

    vector<point> result = cutPolygon(a, b, polygon);

    cout << "Hasil potongan poligon di sisi kiri garis:" << endl;
    for (const auto &pt : result) {
        cout << "(" << pt.x << ", " << pt.y << ")\n";
    }

    return 0;
}
