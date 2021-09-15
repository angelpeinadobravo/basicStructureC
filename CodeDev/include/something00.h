#ifndef SOMETHING00_H
#define SOMETHING00_H

namespace Something {
class Something00 {
public:
    Something00(const int& year, const int& month, const int& day);

protected:
    virtual void dayAction() = 0;

protected:
    int m_year;
    int m_month;
    int m_day;
};
}
#endif // SOMETHING00_H
