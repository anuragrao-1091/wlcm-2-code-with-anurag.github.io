#include <stdio.h>

int main()
{
    char str[5] = {'a', 'b', 'c', 'd', 'e'};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("(%c,%c)\t", str[i],str[j]);
        }
        printf("\n");
    }

    return 0;
}
//Output-
(a,a)	(a,b)	(a,c)	(a,d)	(a,e)	
(b,a)	(b,b)	(b,c)	(b,d)	(b,e)	
(c,a)	(c,b)	(c,c)	(c,d)	(c,e)	
(d,a)	(d,b)	(d,c)	(d,d)	(d,e)	
(e,a)	(e,b)	(e,c)	(e,d)	(e,e)