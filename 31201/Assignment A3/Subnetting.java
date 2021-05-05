package Subnet;

import java.util.*;
import java.lang.Math;


public class Subnetting
{
    // 8+8+8+x
    // powerNumber = 2^x
	
    int powerNumber;

    private int getPowerNumber()
    {
        return powerNumber;
    }

    private void setPowerNumberFromNoOfSubnets( int nSubnets )
    {
        while( 256 % nSubnets != 0 )
        {
            nSubnets++;
        }
        // powerNumber = (int)Math.pow(2,nSubnets);
        powerNumber = 256/nSubnets;
    }

    private int getNumberOfSubnets()
    {
        return (256/powerNumber);
    }


    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String ip,subnetMask = "255.255.";
        int nSubnets;
        boolean isSupernetting = false;
        Subnetting subnetting = new Subnetting(); // created object because main() is static. Either do this or create another class especially for main()
        
        System.out.print("Enter Ip Address : ");
        ip = sc.next();
        String[] test = ip.split("\\.",5);
        for ( String str : test )
        {
            int x = Integer.valueOf(str);
            if( x < 0 || x > 255 )
            {
                System.out.println("Invalid IP");
                System.exit(1);
            }
        }

 
        System.out.print("Enter number of subnets : ");
       
        nSubnets = sc.nextInt();
        subnetting.setPowerNumberFromNoOfSubnets(nSubnets);
        int host = 256 - subnetting.getPowerNumber();
        
        if( isSupernetting )
            subnetMask += host + ".0";
        else
            subnetMask += "255." + host;
        System.out.print("Subnet Mask : ");
        System.out.println(subnetMask);

        if(!isSupernetting)
            System.out.println("Number of subnets formed: " + subnetting.getNumberOfSubnets());
        else
            System.out.println("Number of supernets formed: " + subnetting.getNumberOfSubnets());
        
        int x=(int)Math.ceil(Math.log(nSubnets)/Math.log(2));
		System.out.println("\nNo. of bits borrowed from host :"+x);

        // removing last element from 
        ArrayList<String> test2 = new ArrayList<>(Arrays.asList(test));
        int lastIpBits;
        if( isSupernetting )
        {    
            test2.remove(2);
            test2.remove(2);
            lastIpBits = Integer.valueOf(test[2]);
        }
        else
        {
            test2.remove(3);
            lastIpBits = Integer.valueOf(test[3]);
        }
        
        // converting array back to string
       
        String halfIp = "";
        for( String str : test2 )
        {
            halfIp = halfIp + str + ".";
        }

        // finding range
        int pow = subnetting.getPowerNumber();
        int maxLimit = pow;
        int minLimit = 0;
        System.out.println("\nThe Subnets are : ");
        while( 256 >= maxLimit )
        {
            if( !isSupernetting )
                System.out.print( halfIp + minLimit + " to " + halfIp + (maxLimit-1) );
            else
                System.out.print( halfIp + minLimit + ".0" + " to " + halfIp + (maxLimit-1) + ".0");

            if( minLimit < lastIpBits && maxLimit > lastIpBits )
                System.out.print(" <- ip belongs to this range\n");
            else
                System.out.println();
            minLimit = maxLimit;
            maxLimit += pow;
        }

        sc.close();
    }
}