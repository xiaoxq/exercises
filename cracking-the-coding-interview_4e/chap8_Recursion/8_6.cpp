/*
 * 8_6.cpp
 *
 *  Created on: 2013-5-3
 *      Author: beet
 */

typedef int Color;

void paintFill( Color** image, const int M, const int N,
		const int x, const int y, const Color newColor )
{
	Color oldColor = image[x][y];

	// paint the point
	image[x][y] = newColor;
	// paint around
	if( x>0 && image[x-1][y]==oldColor )
		paintFill(image,M,N,x-1,y,newColor);
	if( y>0 && image[x][y-1]==oldColor )
		paintFill(image,M,N,x,y-1,newColor);
	if( x+1<M && image[x+1][y]==oldColor )
		paintFill(image,M,N,x+1,y,newColor);
	if( y+1<N && image[x][y+1]==oldColor )
		paintFill(image,M,N,x,y+1,newColor);
}
