//Tavishka ta24435 Tavishka
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

//class for managing storage
class Storage {
protected:
    //dynamic 2D array to store coefficients
    vector<vector<int>> data;
    int currentRows;

public:
    Storage(int n) : currentRows(n) {
        data.resize(n);
        for (int i = 0; i < n; ++i) {
              //initialize with -1 (undefined)
            data[i].resize(i + 1, -1);
        }
    }

    //get coefficient at (i,j)
    int get(int i, int j) const {
        if (i >= currentRows || j > i) {
            throw out_of_range("Index is not a part of the triangle..");
        }
        return data[i][j];
    }

    //set coefficient at (i,j)
    void set(int i, int j, int value) {
        if (i >= currentRows || j > i) {
            throw out_of_range("Invalid index.");
        }
        data[i][j] = value;
    }

    //extend storage for more rows
    void extend(int newRows) {
        for (int i = currentRows; i < newRows; ++i) {
            //initialize new rows
            data.push_back(vector<int>(i + 1, -1));
        }
        currentRows = newRows;
    }
};

//Pascal class inheriting from Storage
class Pascal : public Storage {
public:
    Pascal(int n) : Storage(n) {
        //fill the first n rows
        fillPascal(n);
    }

    //method to calculate the coefficient at (i, j)
    int getvalue(int i, int j) {
        if (i >= currentRows) {
            //dynamically extend if out of bounds
            extend(i + 1);
            fillPascal(i + 1);
        }
        if (data[i][j] == -1) {
            //compute if not already calculated
            computeCoefficient(i, j);
        }
        return data[i][j];
    }

    //print Pascal's triangle up to the currentRows
    void print() {
        for (int i = 0; i < currentRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                cout << getvalue(i, j) << " ";
            }
            cout << endl;
        }
    }

private:
    //fill Pascal's triangle up to n rows
    void fillPascal(int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (data[i][j] == -1) {
                    computeCoefficient(i, j);
                }
            }
        }
    }

    //compute the binomial coefficient C(i,j)
    void computeCoefficient(int i, int j) {
        if (j == 0 || j == i) {
            //boundary values are 1
            data[i][j] = 1;
        } else {
            data[i][j] = getvalue(i - 1, j - 1) + getvalue(i - 1, j);
        }
    }
};

int main() {
    //create Pascal triangle with 7 rows
    Pascal triangle(7);
    
    //print Pascal's triangle
    triangle.print();
    
    //get specific values (test case)
    cout << "C(5,2) = " << triangle.getvalue(5, 2) << endl;

    //extend and get values from a larger triangle
    cout << "C(9, 4) = " << triangle.getvalue(9, 4) << endl;

    return 0;
}
