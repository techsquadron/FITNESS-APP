// Header files
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

fstream file;

// Globally defined elements
class fitness
{
    int no, calories, amount, tot = 0;
    char name[50], choice;
    int order[50], quantity[50], count = 0;
    int breakfast_cal = 0, snacks_cal = 0, lunch_cal = 0, prework_cal = 0, dinner_cal = 0;

public:
    void BMI();
    void calories_count();
    void menu();
    void diet();
    void breakfast_menu();
    void breakfast();
    void snacks_menu();
    void snacks();
    void lunch_menu();
    void lunch();
    void prework_menu();
    void prework();
    void dinner_menu();
    void dinner();
    void total();
    void tot_calories();
};

// Calculating BMI
void fitness ::BMI()
{
    int age;
    char gender;
    float weight;
    float height;

    cout << "\n\t\t\t\t\t\t=========================";
    cout << "\n\t\t\t\t\t\t      Calculate BMI" << endl;
    cout << "\t\t\t\t\t\t=========================";

    cout << "\n\n\t\t\t\t\t\tEnter your age: ";
    cin >> age;

    cout << "\t\t\t\t\t\tEnter your gender(m/f): ";
    cin >> gender;

    cout << "\t\t\t\t\t\tEnter your weight in kg: ";
    cin >> weight;

    cout << "\t\t\t\t\t\tEnter your height in meter: ";
    cin >> height;

    float BMI = weight / (height * height);

    cout << "\n\t\t\t\t\t\tYour BMI is: " << BMI << " ";

    if (BMI < 18.5)
    {
        cout << "(You are under weight)" << endl;
        cout << "\n\t\t\t\t\t\tPress any key to continue...";
        getch();
        system("CLS");
        menu();
    }

    else if (BMI >= 18.5 && BMI <= 25)
    {
        cout << "(You are healthy)";
        cout << "\n\t\t\t\t\t\tPress any key to continue...";
        getch();
        system("CLS");
        menu();
    }

    else if (BMI > 25 && BMI <= 30)
    {
        cout << "(You are overweight)";
        cout << "\n\t\t\t\t\t\tPress any key to continue...";
        getch();
        system("CLS");
        menu();
    }

    else
    {
        cout << "(You are obese)";
        cout << "\n\t\t\t\t\t\tPress any key to continue...";
        getch();
        system("CLS");
        menu();
    }
}

// Calculating calories
void fitness ::calories_count()
{
    int age;
    char gender;
    float weight;
    float height;

    cout << "\n\t\t\t\t\t\t==============================";
    cout << "\n\t\t\t\t\t\t      Calculate Calories" << endl;
    cout << "\t\t\t\t\t\t==============================";

    cout << "\n\n\t\t\t\t\t\tEnter your age: ";
    cin >> age;

    cout << "\t\t\t\t\t\tEnter your gender(m/f): ";
    cin >> gender;

    cout << "\t\t\t\t\t\tEnter your weight in kg: ";
    cin >> weight;

    cout << "\t\t\t\t\t\tEnter your height in centimeter: ";
    cin >> height;

    if (gender == 'm')
    {
        int men_calories = (10 * weight) + (6.25 * height) - (5 * age) + 5;
        cout << "\n\t\t\t\t\t\tYour per day calories are " << men_calories << endl;

        float ibw_men = 50 + (0.91 * (height - 152.40));

        if (weight < 50 || ibw_men < 50)
        {
            cout << "\n\t\t\t\t\t\tYou are underweight, follow the chart to increase weight" << endl;
            cout << "\n\t\t\t\t\t\tMild weight gain: " << men_calories + 250 << " calories" << endl;
            cout << "\t\t\t\t\t\tWeight gain: " << men_calories + 500 << " calories" << endl;
            cout << "\t\t\t\t\t\tFast Weight gain: " << men_calories + 1000 << " calories" << endl;
            cout << "\n\t\t\t\t\t\tPress any key to continue...";
            getch();
            system("CLS");
            menu();
        }

        else if (ibw_men > 50 && ibw_men < 75)
        {
            cout << "\n\t\t\t\t\t\tYou are healthy! Stick to the routine";
            cout << "\n\t\t\t\t\t\tPress any key to continue...";
            getch();
            system("CLS");
            menu();
        }

        else if (ibw_men > 75)
        {
            cout << "\n\t\t\t\t\t\tYou are overweight, follow the chart to lose weight";
            cout << "\n\t\t\t\t\t\tMild weight lose: " << men_calories - 250 << " calories" << endl;
            cout << "\t\t\t\t\t\tWeight lose: " << men_calories - 500 << " calories" << endl;
            cout << "\t\t\t\t\t\tFast Weight lose: " << men_calories - 1000 << " calories" << endl;
            cout << "\n\t\t\t\t\t\tPress any key to continue...";
            getch();
            system("CLS");
            menu();
        }
    }

    else if (gender == 'f')
    {
        int women_calories = (10 * weight) + (6.25 * height) - (5 * age) - 161;
        cout << "\n\t\t\t\t\t\tYour per day calories are " << women_calories << endl;

        float ibw_women = 45.5 + (0.91 * (height - 152.40));

        if (weight < 50 || ibw_women < 50)
        {
            cout << "\n\t\t\t\t\t\tYou are underweight, follow the char to increase weight" << endl;
            cout << "\n\t\t\t\t\t\tMild weight gain: " << women_calories + 250 << " calories" << endl;
            cout << "\t\t\t\t\t\tWeight gain: " << women_calories + 500 << " calories" << endl;
            cout << "\t\t\t\t\t\tFast Weight gain: " << women_calories + 1000 << " calories" << endl;
            cout << "\n\t\t\t\t\t\tPress any key to continue...";
            getch();
            system("CLS");
            menu();
        }

        else if (ibw_women > 50 && ibw_women < 75)
        {
            cout << "\t\t\t\t\t\tYou are healthy! Stick to the routine";
            cout << "\n\t\t\t\t\t\tPress any key to continue...";
            getch();
            system("CLS");
            menu();
        }

        else if (ibw_women > 75)
        {
            cout << "\n\t\t\t\t\t\tYou are overweight, follow the chart to lose weight";
            cout << "\n\t\t\t\t\t\tMild weight lose: " << women_calories - 250 << " calories" << endl;
            cout << "\t\t\t\t\t\tWeight lose: " << women_calories - 500 << " calories" << endl;
            cout << "\t\t\t\t\t\tFast Weight lose: " << women_calories - 1000 << " calories" << endl;
            cout << "\n\t\t\t\t\t\tPress any key to continue...";
            getch();
            system("CLS");
            menu();
        }
    }
}

// Accessing Menu
void fitness ::breakfast_menu()
{
    file.open("breakfast.txt", ios ::in);
    cout << "\n\t\t\t\t\t\tBreakfast Menu";
    cout << "\n\t\t\t\t\t\t========================================";
    cout << "\n\t\t\t\t\t\tNo \t\tName \t\tCalories";
    cout << "\n\t\t\t\t\t\t========================================";
    file >> no >> name >> calories;
    while (!file.eof())
    {
        cout << "\n\t\t\t\t\t\t" << no << "\t\t" << name << "\t\t" << calories;
        file >> no >> name >> calories;
    }
    file.close();
}

void fitness ::snacks_menu()
{
    file.open("snacks.txt", ios ::in);
    cout << "\n\t\t\t\t\t\tSnacks Menu";
    cout << "\n\t\t\t\t\t\t========================================";
    cout << "\n\t\t\t\t\t\tNo \t\tName \t\tCalories";
    cout << "\n\t\t\t\t\t\t========================================";
    file >> no >> name >> calories;
    while (!file.eof())
    {
        cout << "\n\t\t\t\t\t\t" << no << "\t\t" << name << "\t\t" << calories;
        file >> no >> name >> calories;
    }
    file.close();
}

void fitness ::lunch_menu()
{
    file.open("lunch.txt", ios ::in);
    cout << "\n\t\t\t\t\t\tLunch Menu";
    cout << "\n\t\t\t\t\t\t========================================";
    cout << "\n\t\t\t\t\t\tNo \t\tName \t\tCalories";
    cout << "\n\t\t\t\t\t\t========================================";
    file >> no >> name >> calories;
    while (!file.eof())
    {
        cout << "\n\t\t\t\t\t\t" << no << "\t\t" << name << "\t\t" << calories;
        file >> no >> name >> calories;
    }
    file.close();
}

void fitness ::prework_menu()
{
    file.open("prework.txt", ios ::in);
    cout << "\n\t\t\t\t\t\tPre-workout Menu";
    cout << "\n\t\t\t\t\t\t========================================";
    cout << "\n\t\t\t\t\t\tNo \t\tName \t\tCalories";
    cout << "\n\t\t\t\t\t\t========================================";
    file >> no >> name >> calories;
    while (!file.eof())
    {
        cout << "\n\t\t\t\t\t\t" << no << "\t\t" << name << "\t\t" << calories;
        file >> no >> name >> calories;
    }
    file.close();
}

void fitness ::dinner_menu()
{
    file.open("dinner.txt", ios ::in);
    cout << "\n\t\t\t\t\t\tDinner Menu";
    cout << "\n\t\t\t\t\t\t========================================";
    cout << "\n\t\t\t\t\t\tNo \t\tName \t\tCalories";
    cout << "\n\t\t\t\t\t\t========================================";
    file >> no >> name >> calories;
    while (!file.eof())
    {
        cout << "\n\t\t\t\t\t\t" << no << "\t\t" << name << "\t\t" << calories;
        file >> no >> name >> calories;
    }
    file.close();
}

// Creating meal
void fitness ::breakfast()
{
    file.open("breakfast.txt", ios ::in);
    if (file)
    {
        file.close();
    }

    breakfast_menu();
    total();

    for (int i = 0; i <= count; i++)
    {
        file.open("breakfast.txt", ios ::in);
        file >> no >> name >> calories;
        while (!file.eof())
        {
            if (no == order[i])
            {
                amount = calories * quantity[i];
                cout << "\t\t\t\t\t\t" << order[i] << "\t" << name << "\t" << quantity[i] << "\t\t" << calories << endl;
                breakfast_cal += amount;
            }

            file >> no >> name >> calories;
        }
        file.close();
    }

    cout << "\n\n\t\t\t\t\t\tTotal calories for breakfast = " << breakfast_cal;
    cout << "\n\n\t\t\t\t\t\tPress any key to continue...";
    getch();
    system("CLS");
    diet();
}

void fitness ::snacks()
{
    file.open("snacks.txt", ios ::in);
    if (file)
    {
        file.close();
    }

    snacks_menu();
    total();

    for (int i = 0; i <= count; i++)
    {
        file.open("snacks.txt", ios ::in);
        file >> no >> name >> calories;
        while (!file.eof())
        {
            if (no == order[i])
            {
                amount = calories * quantity[i];
                cout << "\t\t\t\t\t\t" << order[i] << "\t" << name << "\t" << quantity[i] << "\t\t" << calories << endl;
                snacks_cal += amount;
            }

            file >> no >> name >> calories;
        }
        file.close();
    }

    cout << "\n\n\t\t\t\t\t\tTotal calories for snacks = " << snacks_cal;
    cout << "\n\n\t\t\t\t\t\tPress any key to continue...";
    getch();
    system("CLS");
    diet();
}

void fitness ::lunch()
{
    file.open("lunch.txt", ios ::in);
    if (file)
    {
        file.close();
    }

    lunch_menu();
    total();

    for (int i = 0; i <= count; i++)
    {
        file.open("lunch.txt", ios ::in);
        file >> no >> name >> calories;
        while (!file.eof())
        {
            if (no == order[i])
            {
                amount = calories * quantity[i];
                cout << "\t\t\t\t\t\t" << order[i] << "\t" << name << "\t" << quantity[i] << "\t\t" << calories << endl;
                lunch_cal += amount;
            }

            file >> no >> name >> calories;
        }
        file.close();
    }

    cout << "\n\n\t\t\t\t\t\tTotal calories for lunch = " << lunch_cal;
    cout << "\n\n\t\t\t\t\t\tPress any key to continue...";
    getch();
    system("CLS");
    diet();
}

void fitness ::prework()
{
    file.open("prework.txt", ios ::in);
    if (file)
    {
        file.close();
    }

    prework_menu();
    total();

    for (int i = 0; i <= count; i++)
    {
        file.open("prework.txt", ios ::in);
        file >> no >> name >> calories;
        while (!file.eof())
        {
            if (no == order[i])
            {
                amount = calories * quantity[i];
                cout << "\t\t\t\t\t\t" << order[i] << "\t" << name << "\t" << quantity[i] << "\t\t" << calories << endl;
                prework_cal += amount;
            }

            file >> no >> name >> calories;
        }
        file.close();
    }

    cout << "\n\n\t\t\t\t\t\tTotal calories for prework out = " << prework_cal;
    cout << "\n\n\t\t\t\t\t\tPress any key to continue...";
    getch();
    system("CLS");
    diet();
}

void fitness ::dinner()
{
    file.open("dinner.txt", ios ::in);
    if (file)
    {
        file.close();
    }

    dinner_menu();
    total();

    for (int i = 0; i <= count; i++)
    {
        file.open("dinner.txt", ios ::in);
        file >> no >> name >> calories;
        while (!file.eof())
        {
            if (no == order[i])
            {
                amount = calories * quantity[i];
                cout << "\t\t\t\t\t\t" << order[i] << "\t" << name << "\t" << quantity[i] << "\t\t" << calories << endl;
                dinner_cal += amount;
            }

            file >> no >> name >> calories;
        }
        file.close();
    }

    cout << "\n\n\t\t\t\t\t\tTotal calories for dinner = " << dinner_cal;
    cout << "\n\n\t\t\t\t\t\tPress any key to continue...";
    getch();
    system("CLS");
    diet();
}

void fitness ::total()
{
    cout << "\n\n\t\t\t\t\t\t=====================";
    cout << "\n\t\t\t\t\t\tCreate your diet plan";
    cout << "\n\t\t\t\t\t\t=====================\n";
    do
    {
        cout << "\n\t\t\t\t\t\tPlease enter item no: ";
        cin >> order[count];

        cout << "\n\t\t\t\t\t\tPlease enter quantity: ";
        cin >> quantity[count];
        count++;

        cout << "\n\t\t\t\t\t\tDo you want to add another item? (y/n)";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\n\n\t\t\t\t\t\tTotal Calories";
    cout << "\n\t\t\t\t\t\t========================================";
    cout << "\n\t\t\t\t\t\tNo\tName\tQuantity\tCalories";
    cout << "\n\t\t\t\t\t\t========================================\n";
}

// Calculating total calories
void fitness ::tot_calories()
{
    cout << "\n\n\t\t\t\t\t\t==============================";
    cout << "\n\t\t\t\t\t\t\tTotal calories";
    cout << "\n\t\t\t\t\t\t==============================\n";

    cout << "\n\t\t\t\t\t\t1. Breakfast\t\t     " << breakfast_cal;
    cout << "\n\t\t\t\t\t\t2. Snacks\t\t     " << snacks_cal;
    cout << "\n\t\t\t\t\t\t3. Lunch\t\t     " << lunch_cal;
    cout << "\n\t\t\t\t\t\t4. Prework\t\t     " << prework_cal;
    cout << "\n\t\t\t\t\t\t5. Dinner \t\t     " << dinner_cal;

    tot = breakfast_cal + snacks_cal + lunch_cal + prework_cal + dinner_cal;
    cout << "\n\n\t\t\t\t\t\tTotal calories = " << tot;

    cout << "\n\n\t\t\t\t\t\tPress any key to continue...";
    getch();
    system("CLS");
    menu();
}

void fitness ::diet()
{
    int choice;
    cout << "\n\t\t\t\t\t\t==============================";
    cout << "\n\t\t\t\t\t\t       Create Diet Plan" << endl;
    cout << "\t\t\t\t\t\t==============================";
    cout << "\n\n\t\t\t\t\t\t1. Breakfast" << endl;
    cout << "\t\t\t\t\t\t2. Snacks" << endl;
    cout << "\t\t\t\t\t\t3. Lunch" << endl;
    cout << "\t\t\t\t\t\t4. Pre Workout" << endl;
    cout << "\t\t\t\t\t\t5. Dinner" << endl;
    cout << "\t\t\t\t\t\t6. Return to main menu" << endl;
    cout << "\n\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        system("CLS");
        breakfast();
        break;
    }

    case 2:
    {
        system("CLS");
        snacks();
        break;
    }

    case 3:
    {
        system("CLS");
        lunch();
        break;
    }

    case 4:
    {
        system("CLS");
        prework();
        break;
    }

    case 5:
    {
        system("CLS");
        dinner();
        break;
    }

    case 6:
    {
        system("CLS");
        menu();
        break;
    }

    default:
        cout << "Invalid choice";
    }
}

void fitness ::menu()
{
    int choice;
    cout << "\n\t\t\t\t\t\t===============================";
    cout << "\n\t\t\t\t\t\t   Welcome To Nutrition Noon";
    cout << "\n\t\t\t\t\t\t===============================";
    cout << "\n\n\t\t\t\t\t\t1. Calculate BMI";
    cout << "\n\t\t\t\t\t\t2. Calculate Calories";
    cout << "\n\t\t\t\t\t\t3. Create diet plan";
    cout << "\n\t\t\t\t\t\t4. Check total calories";
    cout << "\n\t\t\t\t\t\t5. Exit";
    cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        system("CLS");
        BMI();
        break;
    }

    case 2:
    {
        system("CLS");
        calories_count();
        break;
    }

    case 3:
    {
        system("CLS");
        diet();
        break;
    }

    case 4:
    {
        system("CLS");
        tot_calories();
        break;
    }

    case 5:
    {
        exit(0);
        break;
    }

    default:
        cout << "Invalid choice";
    }
}

// Main function
int main()
{
    fitness f;
    f.menu();
}