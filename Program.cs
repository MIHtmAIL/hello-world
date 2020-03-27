using System;

namespace myApp
{
    class Program
    {        
        const int ARRAY_SIZE = 11;

        static int Binary_Search(int[] arr, int item)
        {        	
            int low, high, mid, guess;
            low = 0;
			high = ARRAY_SIZE - 1;

        	while (low <= high)
        	{
        		mid = (high + low)/2;
				
				guess = arr[mid];
				
				if (guess == item)
				{
					return mid;
				}
				
				if (guess > item)
				{
					high = mid - 1;
					continue;
				}
				else
				{
					low = mid + 1;
					continue;
				}	

        	}				
        	return 0;
        }

        static void Main(string[] args)
        {
            
          	int[] array = new int [ARRAY_SIZE];

            for(int i = 0;i < 11;i++)
            	{
            		array[i] = i; 
            	}
            	
        	Console.WriteLine(Binary_Search(array, 10));			
        }
    }
}
