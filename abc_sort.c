#include <string.h>
#include <stdio.h>

void print_out(char** arr, int size);

void abc_sort(char** arr, int size, int position, int log) 
{
   
	if(log) printf("The %d`th call; %d - size-----------------------------\n", position, size);
  	
  	// Array for sorting by next position	
	char* arr_for_next_pos[size];		
	// Array for result that will copied to array from argument
	char* sorted[size];				
	// Number of existing elements in sorted
	int len_of_sorted = 0;			
	int len_of_afnp;

	int ph_counter = 0;
	char prev_highests[size];
	// First element in prev_highest will under number 1 because of rare using that symbol
	prev_highests[0] = 1;				
  
  	// Every iteration will handle words by every symbol in alphabet order
  	while(1)	
  	{
  		if(log)
		{
			printf("The %d`th call at cycle|----------------------------|\n", position);

			printf("At finding highest; %c - prev_highest; %d - ph_counter\n", prev_highests[ph_counter-1],
			ph_counter);
		}

  		// Highest for this iteration 
		char highest;                                   
		// At first, highest char is char of first string in arr chosen by position
		highest = arr[0][position];	

		
		//	If highest exists in prev_highests looking for new highest
		for(int i = 0; memchr(prev_highests, arr[i][position], size) != NULL;)
		{					
			i++;
			highest = arr[i][position];
		}

		// If nothing exists in prev_highest common search of highest 
		if(ph_counter == 0)												
		{
			for(int i = 1; i < size; i++)								
			{
				if(highest > arr[i][position])								
				highest = arr[i][position];								
			}												
		}												
		else	// Else also checks prev_highests											
		{												 
			for(int i = 1; i < size; i++)								
			{												
				if(highest > arr[i][position] && memchr(prev_highests, arr[i][position], size) == NULL)	
				highest = arr[i][position];								
			}																								
		}																								
		// Set new highest by ph_counter as index
		prev_highests[ph_counter] = highest;	
		// increment ph_counter for setting new previous highests
		ph_counter++;                                        

		if(log)
		{
			printf("End of finding highest; %c - highest; %d - new_ph_counter; %c - new_prev_highest\n", highest, 
			ph_counter, prev_highests[ph_counter-1]);                                                       
		
			printf("At grouping words with highest litter;\n");
		}

		len_of_afnp = 0;
		// Prepare strings for further sort by next position
		for(int i = 0; i < size; i++)			
		{						
			if(arr[i][position] == highest)			
			{					 
				arr_for_next_pos[len_of_afnp] = arr[i];		
				len_of_afnp++;
			}
		}						
		if(log)
		{
			printf("End of grouping words with highest litter; %d - len_of_afnp; %d - len_of_sorted;\n", len_of_afnp, len_of_sorted);
			print_out(arr_for_next_pos, len_of_afnp);
		} 
		// if in afnp only string that string assigned to sorted
		if(len_of_afnp == 1)									
		{													 
			if(log) printf("'%s' is only string in afnp;\n", arr_for_next_pos[0]);				 
														
			sorted[len_of_sorted] = arr_for_next_pos[0];							
			len_of_sorted++;											
														
			if(log)											
			{												
				printf("%d - new_len_of_sorted\n", len_of_sorted);					
				print_out(sorted, len_of_sorted);							
			} 												
			// If that string was in arg break loop	if not continue												
			if(len_of_sorted == size)										
			{   												
				if(log) printf("End of cycle at %d`th call|----------------------------|\n", position);							
				break;
			}
			if(log) printf("len_of_sorted != size => continue;\n");											
			continue;										
		}
		if(log) printf("len_of_afnp > 1 => Recursive call|-|------------------------|-|\n");
    
		// Recursive call of abc_sort for sorting arr_for_next_pos by next position
		abc_sort(arr_for_next_pos, len_of_afnp, position+1, log);	

		if(log) printf("End of recursive call|-|------------------------|-|\n");

		if(log)	printf("At loading of strings from arr_for_next_pos to sorted;\n");

		// Receive sorted strings from recursive call
		for(int i = 0; i < len_of_afnp;)
		{
				sorted[len_of_sorted] = arr_for_next_pos[i];
				i++;					
				len_of_sorted++;
		}

		if(log) printf("End of loading; new len_of_sorted - %d\n", len_of_sorted);

		// if sorted all strings break loop else continue 
		if(len_of_sorted == size)
		{
			if(log) printf("len_of_sorted equals size;\n");
			break;
		}
		if(log) printf("len_of_sorted doesn`t equals size yet;\n");
		continue;
	}														

	if(log) printf("The end of %d`th call-----------------------------\n", position);
  
	// load all sorted strings in not sorted array
	for(int i = 0; i < size; i++)
	{
		arr[i] = sorted[i];
	}

	if(log)
	{
		print_out(arr, size);
		printf("\n");
	}
}
