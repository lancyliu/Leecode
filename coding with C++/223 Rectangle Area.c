/*
 @ Jun 19 2016 Monday
 @ by Xin Liu 
*/

/************Description of the problem************/
/* LeetCode 223. Rectangle Area
* 
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

*/
	 


// draw a picture, can easily find the way to solve this problem.
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (C-A)*(D- B) + (G-E)*(H-F);
		
        //at first, consider no interaction of two rectangle.
        if( G < A || E > C || F > D || H < B) return result;
        
        // consider the interaction area.
        // caculate the height.
        int height = 0;
        if(D <= H && B >= F) height = D-B;
        else if(D > H && B < F) height = H - F;
        else if(D <= H && B < F) height = D - F;
        else if(D > H && B >= F) height = H - B;
        
        //caculate the width;
        int width = 0;
        if(A >= E && C <= G) width = C - A;
        else if( A < E && C > G) width = G - E;
        else if(A >= E && C > G) width = G - A;
        else if(A < E && C <= G) width = C - E;
        
        int interaction = height * width;
        result = result - interaction;
        return result;
    }
};