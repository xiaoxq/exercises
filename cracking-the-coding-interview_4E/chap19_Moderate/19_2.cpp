/*
 * 19_2.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

enum ChessType
{
	Empty,
	Red,
	Blue
};

ChessType checkDiagonal(ChessType* board)
{
	// right diagonal
	if( board[0][0]==board[1][1] && board[1][1]==board[2][2] )
		return board[1][1];
	// left diagonal
	if( board[0][2]==board[1][1] && board[1][1]==board[2][0] )
		return board[1][1];
	return Empty;
}

ChessType checkRow(ChessType* board)
{
	for( int i=0; i<3; ++i )
		if( board[i][0]!=Empty && board[i][0]==board[i][1] && board[i][1]==board[i][2] )
			return board[i][0];
	return Empty;
}

ChessType checkCol(ChessType* board)
{
	for( int i=0; i<3; ++i )
		if( board[0][i]!=Empty && board[0][i]==board[1][i] && board[1][i]==board[2][i] )
			return board[0][i];
	return Empty;
}

ChessType getWinner(ChessType* board)
{
	ChessType ret;
	if( (ret=checkDiagonal(board)) == Empty )
		if( (ret=checkRow(board)) == Empty )
			ret=checkCol(board);
	return ret;
}
