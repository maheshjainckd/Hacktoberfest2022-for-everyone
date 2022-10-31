
def isPossible(arr, n, m, curr_min):
	studentsRequired = 1
	curr_sum = 0
	for i in range(n):
		if (arr[i] > curr_min):
			return False

		if (curr_sum + arr[i] > curr_min):

			studentsRequired += 1

			# update curr_sum
			curr_sum = arr[i]

			if (studentsRequired > m):
				return False

		# else update curr_sum
		else:
			curr_sum += arr[i]

	return True
def findPages(arr, n, m):

	sum = 0

	# return -1 if no. of books is
	# less than no. of students
	if (n < m):
		return -1

	# Count total number of pages
	for i in range(n):
		sum += arr[i]

	# initialize start as 0 pages and
	# end as total pages
	start, end = 0, sum
	result = 10**9

	# traverse until start <= end
	while (start <= end):
		mid = (start + end) // 2
		if (isPossible(arr, n, m, mid)):
			result = mid
			end = mid - 1

		else:
			start = mid + 1
	return result

# Number of pages in books
arr = [12, 34, 67, 90]
n = len(arr)
m = 2 # No. of students

print("Minimum number of pages = ",
	findPages(arr, n, m))

