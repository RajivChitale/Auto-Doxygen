#include<iostream>
#include<vector>

using namespace std;

/**
@brief This class represents a matrix and addition.

It contains setter functions for rows and columns, and print function.
Constructor arguments are number of rows and columns.
*/
class Matrix{
    private:
    /// @brief  2D vector of floats
    vector<vector<float>> data;

    void printRow(int i){
        for(int j=0; j<data[0].size(); j++){
            cout << data[i][j] << " ";
        }
    }

    public:
    /**
     * @brief   Constructor for Matrix class
     * @param   r   Number of rows
     * @param   c   Number of columns
     * @return  None
     * @note    Initializes a zero matrix of size r x c
    */
    Matrix(int r, int c){
        data = vector<vector<float>>(r, vector<float>(c, 0));
    }

    /// @brief  Sets a particular row equal to a vector 
    /// @param r index of row
    /// @param row vector containing row values
    void setRow(int r, vector<float> row){
        data[r] = row;
    }

    /// @brief  Sets a particular col equal to a vector 
    /// @param c index of col
    /// @param col vector containing col values
    void setCol(int c, vector<float> col){
        for(int i=0; i<col.size(); i++){
            data[i][c] = col[i];
        }
    }

    /// @brief Prints the matrix.
    ///
    /// Prints the matrix to stdout in the form of a 2D array
    void print(){
        for(int i=0; i<data.size(); i++){
            printRow(i);
            cout << endl;
        }
    }

    void add(Matrix m){
        for(int i=0; i<data.size(); i++){
            for(int j=0; j<data[0].size(); j++){
                data[i][j] += m.data[i][j];
            }
        }
    }

    static Matrix add(Matrix m1, Matrix m2){
        Matrix m3 = Matrix(m1.data.size(), m1.data[0].size());
        for(int i=0; i<m1.data.size(); i++){
            for(int j=0; j<m1.data[0].size(); j++){
                m3.data[i][j] = m1.data[i][j] + m2.data[i][j];
            }
        }
        return m3;
    }

};

/**
 @brief   This class represents a square matrix.
*/
class SquareMatrix: public Matrix{
    public:
    SquareMatrix(int r): Matrix(r,r){}
};

int main(){
    Matrix m1 = Matrix(2,2);
    Matrix m2 = Matrix(2,2);
    m1.setRow(0, vector<float>{1,2});
    m2.setCol(0, vector<float>{0.3,0.4});
    m1.print();
    m2.print();
    m1.add(m2);
    m1.print();
    return 0;
}