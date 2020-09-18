#include<iostream>
#include<sstream>

using namespace std;

class Date {
private:
    int _year;
    int _month;
    int _day;
public:
    Date()
    {
        _year = 0;
        _month = 0;
        _day = 0;
    }
    Date(int _year,int _month,int _day)
    {
        this->_year = _year;
        this->_month = _month;
        this->_day = _day;
    }

    int GetYear() const
    {
        return _year;
    }
    int GetMonth() const
    {
        return _month;
    }
    int GetDay() const
    {
        return _day;
    }

    void SetYear(int _year)
    {
        this->_year = _year;
    }

    void SetMonth(int _month)
    {
        this->_month = _month;
    }

    void SetDay(int _day)
    {
        this->_day = _day;
    }
};

Date ParseDate(string date)
{
    istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw invalid_argument("Incorrect date format:"+date);
    }
    return {year, month, day};
}

ostream& operator<<(ostream &out, const Date &dat)
{
    return out<<dat.GetYear()<<"-"<<dat.GetMonth()<<"-"<<dat.GetDay();
}

istream& operator>>(istream &in, Date &dat)
{
    int integer;
    in>>integer;
    dat.SetYear(integer);
    in>>integer;
    dat.SetMonth(integer);
    in>>integer;
    dat.SetDay(integer);
    return in;
}
int main()
{
    string s1;
    cin>>s1;
    cout<<ParseDate(s1)<<endl;
    Date dat1;
    cin>>dat1;
    cout<<dat1<<endl;
}