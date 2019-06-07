//
// Created by Jorge on 7/06/2019.
//

#ifndef PC3_CLASES_GENERICAS_MATRIZ_H
#define PC3_CLASES_GENERICAS_MATRIZ_H

#include <vector>
#include <iosfwd>

template <typename T>
class Matrix
{
    std::vector<std::vector<T>> matrix;
    int filas;
    int columnas;
public:
    Matrix(int filas_, int columnas_):
            matrix(filas_),
            filas(filas_),
            columnas(columnas_)
    {
        for (auto& row : matrix)
        {
            row.resize(columnas);
            for (auto& cell : row)
            {
                cell = 0;
            }
        }
    }

    Matrix(int filas_, int columnas_, const T& value) :
            matrix(filas_),
            filas(filas_),
            columnas(columnas_)
    {
        for (auto& row : matrix)
        {
            row.resize(columnas, value);
        }
    }

    Matrix(const Matrix& other) = default;

    Matrix(Matrix&& other) :
            matrix(std::move(other.matrix))
    {
        filas = other.filas;
        columnas = other.columnas;
    }

    Matrix& operator=(const Matrix& other) = default;

    Matrix& operator=(Matrix&& other)
    {
        std::swap(matrix, other.matrix);
        filas = other.filas;
        columnas = other.columnas;
        return *this;
    }

    Matrix& operator+=(const Matrix& rhs)
    {
        if (filas != rhs.filas || columnas != rhs.columnas)
        {
            std::cout<<"LAS MATRICES NO TIENEN LAS MISMAS DIMENSIONES\n";
        }
        else{
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    matrix[i][j] += rhs[i][j];
                }
            }
            return *this;
        }
    }
    int rows()
    {
        return filas;
    }

    int columns()
    {
        return columnas;
    }

    const int rows() const
    {
        return filas;
    }

    const int columns() const
    {
        return columnas;
    }

    std::vector<T>& operator[](int row)
    {
        return matrix[row];
    }

    const std::vector<T>& operator[](int row) const
    {
        return matrix[row];
    }
};

template <typename T>
bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if (lhs.rows() != rhs.rows() || lhs.columns() != rhs.columns())
    {
        return false;
    }

    for (int i = 0; i < lhs.rows(); i++)
    {
        for (int j = 0; j < lhs.columns(); j++)
        {
            if (lhs[i][j] != rhs[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool operator!=(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
Matrix<T> operator+(Matrix<T> lhs, const Matrix<T>& rhs)
{
    return lhs += rhs;
}

template <typename T>
std::istream& operator >> (std::istream& is, Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.rows(); i++)
    {
        for (int j = 0; j < matrix.columns(); j++)
        {
            is >> matrix[i][j];
        }
    }

    return is;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.rows(); i++)
    {
        for (int j = 0; j < matrix.columns(); j++)
        {
            os << matrix[i][j] << ' ';
        }
        os << "\n";
    }

    return os;
}

#endif //PC3_CLASES_GENERICAS_MATRIZ_H
