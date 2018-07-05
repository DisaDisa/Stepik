struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;
    

private:
    int numerator_;
    int denominator_;
    
    friend bool operator==(Rational const&, Rational const&);
    friend bool operator!=(Rational const&, Rational const&);
    friend bool operator<(Rational const&, Rational const&);
    friend bool operator>(Rational const&, Rational const&);
    friend bool operator<=(Rational const&, Rational const&);
    friend bool operator>=(Rational const&, Rational const&);
    
};

int gcd(int n, int m) {
    while (n != 0 && m != 0) {
        n %= m;
        int k = n;
        n = m;
        m = k;
    }
    return n + m;
}
    
int lcm(int n, int m) {
    return n / gcd(n, m) * m;
}

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);


bool operator==(Rational const& r1, Rational const& r2) {
    return r1.numerator_ * r2.denominator_ == r1.denominator_ * r2.numerator_;
}

bool operator!=(Rational const& r1, Rational const& r2) {
    return !(r1 == r2);
}

bool operator<(Rational const& r1, Rational const& r2) {
    int lcm = lcm(r1.denominator_, r2.denominator_);
    return r1.numerator_ * (lcm / r1.denominator_) < r2.numerator_ * (lcm / r2.denominator_);
}

bool operator>(Rational const& r1, Rational const& r2) {
    return r2 < r1;
}

bool operator<=(Rational const& r1, Rational const& r2) {
    return !(r1 > r2);
}

bool operator>=(Rational const& r1, Rational const& r2) {
    return !(r1 < r2);
}
    