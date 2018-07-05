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
    
    Rational & operator+=(Rational const& r) {
    	int lcm = lcm(denominator_, r.denominator_);
    	numerator_ = numerator_ * (lcm / denominator_) + r.numerator_ * (lcm / r.denominator_);
    	denominator_ = lcm;
    	return *this;
    }	

    Rational & operator-=(Rational const& r) {
    	int lcm = lcm(denominator_, r.denominator_);
    	numerator_ = numerator_ * (lcm / denominator_) - r.numerator_ * (lcm / r.denominator_);
    	denominator_ = lcm;
    	return *this;
    }

    Rational & operator*=(Rational const& r) {
    	numerator_ *= r.numerator_;
    	denominator_ *= r.denominator_;
    	return *this;
    }

	Rational & operator/=(Rational const& r) {
		numerator_ *= r.denominator_;
		denominator_ *= r.numerator_;
		return *this;
	}	
    
    Rational operator-() const { 
        return Rational(-numerator_, denominator_);
    }
    
    Rational operator+() const {
        return Rational(numerator_, denominator_);
    }

private:
    int numerator_;
    int denominator_;
    
    int gcd(int n, int m) {
        while (n != 0 && m != 0) {
            n %= m;
            std::swap(n, m);
        }
        return n + m;
    }
    
    int lcm(int n, int m) {
        return n / gcd(n, m) * m;
    }
};