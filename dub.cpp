#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>


void setArrayLen(int& length);
int findDup(std::vector<int>& numbers);

int main()
{
    srand(time(0));

    int amount_of_numbers;
    setArrayLen(amount_of_numbers);

    std::vector<int> numbers(amount_of_numbers); 
    
    for(int i = 0; i < amount_of_numbers - 1; i++) numbers[i] = i;

    //getting random number from 0 to n
    int random_number =  rand() % (amount_of_numbers + 1);
    std::cout << "random number which will be dupped: " << random_number << std::endl;

    numbers[amount_of_numbers - 1] = random_number;

    std::cout << "duplicate is: " << findDup(numbers) << std::endl;
    return 0;
}



//doing it since in findDup function expected sum equals n*(n-1) which tends to n^2 and...
//44721^2 is slithgly less when integer max number
void setArrayLen(int& n)
{
    bool is_number_big = false;
    do
    {   
        std::cout << "enter amount of numbers in array: ";
        std::cin >> n;
        if(n > 44721)
        {
            is_number_big = true;
            std::cout << "your number is too big, please try again\n";
        }
        else
        {
            is_number_big = false;
        }
    }while(is_number_big);

}

//by the set of problem, we have an array of n+1 numbers from 0 to n-1
//my idea is to count refernce sum like if all numbers were unique...
//and compare it with sum actual sum
//difference between those two sums is needed duplicate
int findDup(std::vector<int>& numbers) {
    int n = numbers.size() - 1; 
    int ref_sum = n * (n - 1) / 2; 
    int real_sum = 0;

    for (int num : numbers) real_sum += num;

    return real_sum - ref_sum;
}