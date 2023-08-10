#include <iostream>
#include <string>
using namespace std;

class applicant
{
private:
    int age;
    string address;
    int m_sal;
    int h_loan;
    int p_loan;
    int no_check_bounce;
    char own_house;
    char spouse_working;
    char dependent_parents;
    int company_tier;

public:
    void get_data();
    int calc_liability();
    void display_score();
};

void applicant::get_data()
{

    cout << "Age: ";
    cin >> age;

    cin.ignore(); // Clear the newline character
    cout << "Address: ";
    getline(cin, address);

    cout << "Monthly salary: ";
    cin >> m_sal;

    cout << "Total home loan: ";
    cin >> h_loan;

    cout << "Total personal loan: ";
    cin >> p_loan;

    cout << "Number of cheques bounced in the last six months: ";
    cin >> no_check_bounce;

    cout << "Own house? (Y or N): ";
    cin >> own_house;

    cout << "Spouse Working (Y or N): ";
    cin >> spouse_working;

    cout << "Dependent Parents (Y or N): ";
    cin >> dependent_parents;

    cout << "Company tier? (1, 2, or 3): ";
    cin >> company_tier;
}

int applicant::calc_liability()
{
    int score = 0;

    int liability;
    if (age > 22 && age <= 30)
    {
        score += 2;
    }
    else if (age > 30 && age <= 35)
    {
        score += 1;
    }
    else
    {
        score -= 1;
    }

    liability = h_loan + p_loan;
    if (liability <= m_sal / 4)
    {
        score += 5;
    }
    else if (liability <= m_sal / 3)
    {
        score += 3;
    }
    else if (liability <= m_sal / 2)
    {
        score += 2;
    }
    else
    {
        score -= 1;
    }

    if (no_check_bounce == 0)
    {
        score += 1;
    }
    else if (no_check_bounce == 1)
    {
        score -= 1;
    }
    else if (no_check_bounce > 1)
    {
        score -= 2;
    }

    if (p_loan > h_loan)
    {
        score -= 1;
    }
    else
    {
        score += 1;
    }

    if (own_house == 'Y' || own_house == 'y')
    {
        score += 1;
    }

    if (spouse_working == 'Y' || spouse_working == 'y')
    {
        score += 1;
    }

    if (dependent_parents == 'Y' || dependent_parents == 'y')
    {
        score -= 1;
    }
    else
    {
        score += 1;
    }

    if (company_tier == 1)
    {
        score += 3;
    }
    else if (company_tier == 2)
    {
        score += 2;
    }
    else if (company_tier == 3)
    {
        score += 1;
    }

    return score;
}

void applicant::display_score()
{
    int sc = calc_liability();

    if (sc > 9)
    {
        cout << "The applicant  is at low risk.\nCredit score = " << sc << "\nCredit can be given\n";
    }
    else if (sc > 5)
    {
        cout << "The applicant  is at average risk.\nCredit score = " << sc << "\nCredit can be given with due precaution\n";
    }
    else
    {
        cout << "The applicant  is at high risk.\nCredit score = " << sc << "\nCredit cannot be given\n";
    }
}

int main()
{
    while (true)
    {
        applicant a;
        cout << "\n------Credit calc------\n";
        cout << "-------------------------------\n";
        cout << "1 - Enter the loan applicant's details\n";
        cout << "2 - Display credit score\n";
        cout << "3 - Exit\n";
        cout << "\nSelect the option by typing the numeric code \n";

        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            a.get_data();
            break;
        case 2:
            a.display_score();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
