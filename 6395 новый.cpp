#include <iostream>
using namespace std;

int main() {
    // Задание 1
    cout << "bool: "        << sizeof(bool)        << endl
         << "char: "        << sizeof(char)        << endl
         << "int: "         << sizeof(int)         << endl
         << "float: "       << sizeof(float)       << endl
         << "double: "      << sizeof(double)      << endl
         << "short int: "   << sizeof(short int)   << endl
         << "long int: "    << sizeof(long int)    << endl
         << "long double: " << sizeof(long double) << endl;

    // Задание 2
    int a = 127;

    cout << endl;
    cout << (a & 1)   << ' '
         << (a & 2)   << ' '
         << (a & 4)   << ' '
         << (a & 8)   << ' '
         << (a & 16)  << ' '
         << (a & 32)  << ' '
         << (a & 64)  << ' '
         << (a & 128) << endl;

    cout << ((a & (1 << 0)) ? '1' : '0')
         << ((a & (1 << 1)) ? '1' : '0')
         << ((a & (1 << 2)) ? '1' : '0')
         << ((a & (1 << 3)) ? '1' : '0')
         << ((a & (1 << 4)) ? '1' : '0')
         << ((a & (1 << 5)) ? '1' : '0')
         << ((a & (1 << 6)) ? '1' : '0')
         << ((a & (1 << 7)) ? '1' : '0')
         << ((a & (1 << 8)) ? '1' : '0') << endl;

    cout << endl;
    cout << "a: " << a << " &a: " << &a << endl;
    cout << endl;

    int order_i = sizeof(int) * 8;
    unsigned int mask_i = 1u << (order_i - 1);

    for (int i = 0; i < order_i; i++) {
        if (a & (mask_i >> i))
            cout << '1';
        else
            cout << '0';
    }
    cout << endl << endl;

    // Задание 3
    union {
        float pi;
        unsigned int pi_i;
    } x;
    x.pi = 3.14f;

    cout << "pi: " << x.pi << " &pi: " << &x.pi
         << " pi_i: " << x.pi_i << " &pi_i: " << &x.pi_i << endl;

    int order_pi = sizeof(float) * 8;
    unsigned int mask_pi = 1u << (order_pi - 1);
    for (int i = 0; i < order_pi; i++) {
        if (x.pi_i & (mask_pi >> i))
            cout << '1';
        else
            cout << '0';
    }
    cout << endl << endl;

    // Задание 4
    union {
        double d;
        unsigned long long d_i;
    } y;
    y.d = 3.14;

    int order_d = sizeof(double) * 8;
    unsigned long long mask_d = 1ULL << (order_d - 1);

    cout << "double 3.14: ";
    for (int i = 0; i < order_d; i++) {
        if (y.d_i & (mask_d >> i))
            cout << '1';
        else
            cout << '0';
    }
    cout << endl << endl;

    int temp = 127;
    cout << "int 127:     ";
    for (int i = 0; i < order_i; i++) {
        if (temp & (mask_i >> i))
            cout << '1';
        else
            cout << '0';
    }
    cout << endl << "temp = " << temp << endl << endl;

    // Задание 5
    int type, pos, op;
    cout << "Тип числа (1 - int, 2 - float, 3 - double): ";
    cin >> type;

    if (type == 1) {
        int z;
        cout << "Введите int: ";
        cin >> z;
        cout << "Позиция бита (0..31): ";
        cin >> pos;
        cout << "Операция (1 - сбросить &, 2 - установить |, 3 - инвертировать ^): ";
        cin >> op;

        if (pos < 0 || pos > 31) {
            cout  << endl;
        } else {
            unsigned int u = (unsigned int)z;
            unsigned int mask = 1u << pos;

            cout << "До:    ";
            for (int i = 31; i >= 0; i--) cout << ((u & (1u << i)) ? '1' : '0');
            cout << "  = " << z << endl;

            if (op == 1)      u = u & ~mask;
            else if (op == 2) u = u | mask;
            else              u = u ^ mask;

            cout << "После: ";
            for (int i = 31; i >= 0; i--) cout << ((u & (1u << i)) ? '1' : '0');
            cout << "  = " << (int)u << endl;
        }
    }
    else if (type == 2) {
        union {
            float f;
            unsigned int u;
        } q;
        cout << "Введите float: ";
        cin >> q.f;
        cout << "Позиция бита (0..31): ";
        cin >> pos;
        cout << "Операция (1 - сбросить &, 2 - установить |, 3 - инвертировать ^): ";
        cin >> op;

        if (pos < 0 || pos > 31) {
            cout <<  endl;
        } else {
            unsigned int mask = 1u << pos;

            cout << "До:    ";
            for (int i = 31; i >= 0; i--) {
                cout << ((q.u & (1u << i)) ? '1' : '0');
                if (i == 31 || i == 23) cout << " ";
            }
            cout << "  = " << q.f << endl;

            if (op == 1)      q.u = q.u & ~mask;
            else if (op == 2) q.u = q.u | mask;
            else              q.u = q.u ^ mask;

            cout << "После: ";
            for (int i = 31; i >= 0; i--) {
                cout << ((q.u & (1u << i)) ? '1' : '0');
                if (i == 31 || i == 23) cout << " ";
            }
            cout << "  = " << q.f << endl;
        }
    }
    else if (type == 3) {
        union {
            double d;
            unsigned long long u;
        } w;
        cout << "Введите double: ";
        cin >> w.d;
        cout << "Позиция бита (0..63): ";
        cin >> pos;
        cout << "Операция (1 - сбросить &, 2 - установить |, 3 - инвертировать ^): ";
        cin >> op;

        if (pos < 0 || pos > 63) {
            cout <<  endl;
        } else {
            unsigned long long mask = 1ULL << pos;

            cout << "До:    ";
            for (int i = 63; i >= 0; i--) {
                cout << ((w.u & (1ULL << i)) ? '1' : '0');
                if (i == 63 || i == 52) cout << " ";
            }
            cout << "  = " << w.d << endl;

            if (op == 1)      w.u = w.u & ~mask;
            else if (op == 2) w.u = w.u | mask;
            else              w.u = w.u ^ mask;

            cout << "После: ";
            for (int i = 63; i >= 0; i--) {
                cout << ((w.u & (1ULL << i)) ? '1' : '0');
                if (i == 63 || i == 52) cout << " ";
            }
            cout << "  = " << w.d << endl;
        }
    }
    else {
        cout  << endl;
    }

        int number = 5;

    int inverted = number ^ 0x80000000;
    int doubled  = number << 1;

    cout << endl;
    cout << "number = " << number << endl;
    cout << "inverted = " << inverted << endl;
    cout << "doubled = " << doubled << endl;
    cout << "number after = " << number << endl;

    return 0;
}
