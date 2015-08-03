# StalBIAS

StalBIAS is a QT Cross Platform program for determining stalagmite growth. We use a open formula by  Baker et al., 1998 found in the paper ["Testing theoretically predicted stalagmite growth rate with Recent annually laminated samples: Implications for past stalagmite deposition"](http://www.sciencedirect.com/science/article/pii/S0016703797003438) to deduce the empirical growth of a stalagmite given certain conditions.

## Features 

 - Import from CSV files
 - Processing of data which gives you growth rates and apparent calcium concentrations and their respective errors
 - Auto sorting of the data into different seasons
	 - Fast growth
	 - Slow growth
	 - Winter
	 - Summer
 - Plotting of the data with interactive mouse controls
 - Student's T-testing for different season growth rates
 - Biasing calculations

## Equations:

Empirical Growth Equation:

    R0 = 1174 = 1174*(cCa - appcCa) * (FilmThickness/DripInt) *(1.0 - e^exp)
    
    Where exp:
    
     exp = (-1.0 * (alpha/FilmThickess) * DripInterval)
    
    Where alpha:
    
     alpha= (0.52 + (0.04*Temp) + (0.004*Temp^2)) * 10^-7;

Apparent Calcium Concentration

    appcCa = (5.872* pCO2^0.2526)+((-0.0167*Temp)+1.5146)) * 0.5;

Averaging, Variance, Standard Deviation use the standard formulas.

## Input File
 The input file of this program is a CSV file with a Header, in the following format:

    Timestamp,Drip Interval (s),Error (s),Film Thickness (m),Error (m),Temperature (degC),Error (degC),pCO2 (atm),Error (atm),cCa (mol/m3),Error (mol/m3)
    04/28/2005 00:00:00,4,1,0.0001,0.00005,18.27007299,0.2,0.000669456,0.00003,2.02345153,0.01

 - Timestamp: Must be written: [MM/DD/YYYY 00:00:00] Specific time is a feature we plan on including

Sample Files are included in the src folder

### To Do list:

 - Export as CSV
 - Export graphs as jpg, png, svg, tiff.
 - Add additional controls to customize seasons better.
 - Bug fixes.


----------
If anyone is interested in this proyect or would like to help, contact us!

####Credits:


The AlgLib Commutiny @ http://www.alglib.net/
The QT Community @ http://qt-project.org/

Thanks,  Rolf & Fran89.
 - 
