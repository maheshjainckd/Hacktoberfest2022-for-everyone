# <center> Hacktober Fest 2021 For Everyone! </center>

![Hacktoberfest 2021](hacktoberfest2021.png)

<p align="center">
   <img alt="GitHub pull-requests" src="https://img.shields.io/github/issues-pr/maheshjainckd/Hacktoberfest2021-for-everyone">
   <img alt="GitHub forks" src="https://img.shields.io/github/forks/maheshjainckd/Hacktoberfest2021-for-everyone">
   <img alt="contributors" src="https://img.shields.io/github/contributors/maheshjainckd/Hacktoberfest2021-for-everyone">
   <img alt="GitHub stars" src="https://img.shields.io/github/stars/maheshjainckd/Hacktoberfest2021-for-everyone">
   <img alt="visits" src="https://badges.pufler.dev/visits/maheshjainckd/Hacktoberfest2021-for-everyone">
</p>

# Upload Projects or Different Types of Programs in any Language

Use this project to make your first contribution to an open source project on GitHub. Practice making your first pull request to a public repository before doing the real thing!

# What is Hacktoberfest?

Hacktoberfest is a program by Digital Ocean, DEV and Github, where you can easily win a T-Shirt just by making 4 pull requests in the month of October to any open source projects on Github.

## Steps to follow:

### 1. Register for Hacktoberfest

##### https://hacktoberfest.digitalocean.com/

### 2. Add Project/Program in any Language you like:

Add any of your simple or complex Project/Program in any language you like in this repository by clicking "Add File -> Create new File".

### 3. Mention your name in the contributors.html file

https://github.com/maheshjainckd/Hacktoberfest2021-for-everyone/blob/main/contributors.html

### 4. Create Pull Request:

Once you have completed these steps, you are ready to start contributing by clicking on Create Pull Request.

### 5. Give this Project a Star:

If you liked working on this project, please share this project as much as you can and star this project to help as many people in opensource as you can.


## Note:

1. Don't Create Pull Request to update "readme.md" File.
2. Upload or Create File in Specified Language Folder.
3. If Specified Language Folder not Found then Create Folder and then Upload or Create File.
4. Please mention the extention of files while creating them (e.g if file is of java language create file named "xyz.java").

## Special thanks:+1: to:

* [dikshantrajput](https://github.com/dikshantrajput)

contributor Rohan Singh Rathore
kadanes algorithm

// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}


