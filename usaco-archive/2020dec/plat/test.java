import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
 * Name Teddy Dong
 * Date 1/12/2021
 * APCS Period 6
 * DNA Project 
 * 
 * Program Description
 */

public class DNA
{
	public static final int MINIMUM_LENGTH = 4;
	public static final int CG_PERCENTAGE = 30;
	public static final int NUM_NUCLEOTIDES = 4;
	public static final int CODON_LENGTH = 3;
    /* 
     * Your main should call startAnalysis with the name of your current
     * test file. You may prompt the user for the filename if you wish for
     * more flexible testing.
     */
    public static void main(String[] args) throws FileNotFoundException
    {
		startAnalysis("DNA.txt");
    }
    
    /*
     * This method replaces what would normally be your main method.
     * Do not modify the method header at all! This will be used for testing
     */
    public static void startAnalysis(String filename) throws FileNotFoundException
    {
    	File file = new File("./input/DNA.txt");
		Scanner input = new Scanner(file);
		String nucleotides = "";
		int[] numnuc = new int[NUM_NUCLEOTIDES];
		double[] percentages = new double[NUM_NUCLEOTIDES];
		
        System.out.print("Welcome to the DNA Scanner! Results for " + file.getName() + ":");
        while(input.hasNext()) {
        		
        		System.out.println();
    			System.out.println();
        		System.out.println("Name: " + input.next()+ input.nextLine());
        		
        		nucleotides = input.next().toUpperCase();
        		
        		printNucleotides(nucleotides);	
        		
        		countNucleotides(numnuc,nucleotides);
        		    		
        		percentages = massPercentages(numnuc);
        		
        		codon(nucleotides);
        		
				encodeProtein(percentages ,nucleotides);
        		
        		resetArray(numnuc);
        	
        }
    }
    
    public static void encodeProtein(double[]percentages, String nucleotides) {
    		System.out.print("Encodes a protein: ");
    		if (goodPercentage(percentages) && goodLength(nucleotides) && goodBeg(nucleotides) && goodEnd(nucleotides)) {
    			System.out.print("yes");
    		}
    		else {
    			System.out.print("no");
    		}

    }
    
    public static boolean goodPercentage (double[] percentages) {
    	if (percentages[1]+percentages[2] < CG_PERCENTAGE) {
    		return false;
    	}
    	return true;
    }
    
    
    public static boolean goodLength (String nucleotides) {
    	if (nucleotides.length()/3 >= MINIMUM_LENGTH) {
    		return true;
    	}
    	
    	return false;
    }
    
    
    public static boolean goodBeg (String nucleotides) {
    	if (nucleotides.substring(0,3).equals("ATG")) {
    		return true;
    	}
    	return false;	
    }
    
    public static boolean goodEnd (String nucleotides) {
    	
    	if (nucleotides.substring(nucleotides.length() -3, nucleotides.length()).equals("TAA") ) {
    		return true;
    	}
    	
    	else if (nucleotides.substring(nucleotides.length() -3, nucleotides.length()).equals("TAG") ) {
    		return true;
    	}
    	
    	else if (nucleotides.substring(nucleotides.length() -3, nucleotides.length()).equals("TGA") ) {
    		return true;
    	}
    	
    	return false;
    }
    
    
    public static void codon (String input) {
    	
    	System.out.print("Codons: [");
    	
    	for (int i = 0; i < input.length()/CODON_LENGTH; i++) {
    		String codon = input.substring(i*CODON_LENGTH,i*CODON_LENGTH + CODON_LENGTH);
    		System.out.print(codon);
    		if (i != input.length()/CODON_LENGTH-1) System.out.print(", ");
    		
    	}
    	System.out.print("]");
		System.out.println();

    	
    }
    
    
    
    public static double[] massPercentages (int[] a) {
    	double total = 0;
    	double[] temp1 = new double[NUM_NUCLEOTIDES];
    	double[] temp2 = new double[NUM_NUCLEOTIDES];
    	
    	for (int i = 0; i < a.length; i++) {
    		if (i == 0) {
    			total += a[0]*135.128;
    		}
    		else if (i == 1) {
    			total += a[1] * 111.103;
    		}
    		
    		else if (i == 2) {
    			total += a[2] * 151.128;
    		}
    		
    		else {
    			total += a[3] * 125.107;
    		}
    	}
    	
    	for (int d = 0; d < NUM_NUCLEOTIDES; d++) {
    		if (d == 0) {
    			temp1[0] =(a[0]*135.128*100);
    		}
    		else if (d == 1) {
    			temp1[1] = a[1] * 111.103*100;
    		}
    		
    		else if (d == 2) {
    			temp1[2] = a[2] * 151.128*100;
    		}
    		
    		else {
    			temp1[3] = a[3] * 125.107*100;
    		}
    	}
    	
    	for (int o = 0; o < NUM_NUCLEOTIDES; o++){
    		temp2[o] = temp1[o]/total;
    	}
    	
    	System.out.print("Mass percentages: ");
		
		System.out.print('[');
		for (int h = 0; h < temp2.length; h++) {
		     if (h != 0) System.out.print(", ");
		     System.out.printf("%.2f",temp2[h]);
		}
		System.out.println(']');
		
		for (int d = 0; d < NUM_NUCLEOTIDES; d++) {
    		if (d == 0) {
    			temp1[0] =(a[0]*135.128*100);
    		}
    		else if (d == 1) {
    			temp1[1] = a[1] * 111.103*100;
    		}
    		
    		else if (d == 2) {
    			temp1[2] = a[2] * 151.128*100;
    		}
    		
    		else {
    			temp1[3] = a[3] * 125.107*100;
    		}
    	}
    	
    	for (int o = 0; o < NUM_NUCLEOTIDES; o++){
    		temp2[o] = temp1[o]/total;
    	}
    	
		return temp2;
    } 	
    
    
    
    public static void resetArray (int[] arr) {
    	for (int i = 0; i < arr.length; i++) {
    		arr[i] = 0;
    	}
    }
    
    
    
    public static void printNucleotides (String input) {
    	System.out.println("Nucleotides: " + input);
    }
    
    
    
    public static void countNucleotides (int[] arr, String input) {
    	for (int i = 0; i < input.length(); i++) {
			
			if (input.charAt(i) == ('A')) {
				arr[0] += 1;
			}
			
			else if (input.charAt(i) == ('C')) {
				arr[1] += 1;
			}
			
			else if (input.charAt(i) == ('G')) {
				arr[2] += 1;
			}
			
			else{
				arr[3] += 1;
			}
    }
    	System.out.print("Nucleotide counts: ");
		
		System.out.print('[');
		for (int a = 0; a < arr.length; a++) {
		     if (a != 0) System.out.print(", ");
		     System.out.print(arr[a]);
		}
		System.out.println(']');
    
}
    
}


