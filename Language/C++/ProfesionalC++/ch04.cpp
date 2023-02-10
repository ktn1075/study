#include<string>
#include<cstring>
#include<iostream>
#include<string_view>

using namespace std;

template <typename PieceType>
class GameBoard
{
public:
    void setPieceAt(size_t x, size_t y, PieceType* piece)
    {

    }
    PieceType* getPieceAt(size_t x, size_t y)
    {

    }
    bool isEmpty(size_t x, size_t y) const
    {

    }
};

class jangiType
{

};

class ChessType
{

};

int main(void)
{
    GameBoard <ChessType> c;
    GameBoard <jangiType> j;
}