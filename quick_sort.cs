using System;

namespace myApp
{
    class Program
    {        

    	static int[] Concat(int[] ar1, int[] ar2)
    	{
    		int[] total = new int[ar1.Length + ar2.Length];     // P.S - program written in .NET Core 3.1!

    		for (int i = 0; i < ar1.Length; i++)
    		{
    			total[i] = ar1[i];
    		}

    		int j = 0;

    		for (int i = ar1.Length; i < ar1.Length + ar2.Length; i++ )
    		{
    			
    			total[i] = ar2[j];
    			j++;
    		}

    		return total;
    	}

    	
     
     	static int[] quick_sort(int[] array)
     	{
     		if (array.Length < 2) 
     		{													// Base Case
     			return array;
     		}

     		int pivot_index = 0;
     		int pivot = array[pivot_index];						// Pivot Initialization
     		int[] pivot_in_arr = {pivot};						
     		
     		int[] newArray = new int[array.Length - 1]; 		// New array for quick sort separately from pivot element!!

     		int j = 0;	// Var for apart subscripting of new, 'smaller' and 'higher' array
     		for (int i = 0; i < array.Length; i++)
     		{
     			if (i != pivot_index)
     			{												// Cast elements for new array
     				newArray[j] = array[i];
     				j++;
     			}
     		}

     		int length = 0;
     		for (int i = 0; i < newArray.Length; i++)			
     		{     			
     			if (newArray[i] <= pivot)						// Defining length of 'smaller' array and array itself
     			{
     				length++;     				
     			}
     		} 

     		int[] smaller = new int[length];					

     		j = 0;	 
     		for (int i = 0; i < newArray.Length; i++)
     		{
     			
     			if (newArray[i] <= pivot)						// Cast elements for 'smaller' array
     			{
     				smaller[j] = newArray[i];
     				j++;     				
     			}
     		} 

     		length = 0;
     		for (int i = 0; i < newArray.Length; i++)
     		{	
     			if (newArray[i] > pivot)						// Defining length of 'higer' array and defining itself
     			{     				
     				length++;
     			}     			
     		} 

     		int[] higher = new int[length];

     		j = 0;
     		for (int i = 0; i < newArray.Length; i++)
     		{
     			
     			if (newArray[i] > pivot)
     			{
     				higher[j] = newArray[i];
     				j++;     				
     			}
     		} 

     		int[] sorted = Concat(Concat(quick_sort(smaller), pivot_in_arr), quick_sort(higher)); // Concatanation arrays

     		return sorted;		 

     	}

        static void Main(string[] args)
        {
                 
        	int[] array = {2,7,4,13,2,9,0};

        	for (int i = 0; i < array.Length; i++)
        	{
        		Console.WriteLine(quick_sort(array)[i]);
        	}        	
         				        
        }
    }
}
