# Read the first digit into block #1
,
>-----------------------------------------------

# Read the second digit into block #2
>,
>++++++ # Set up a counter in block #3 (counter for the outer loop)

[
	# Outer loop: subtract 1 from counter in block #3
	>++++++++ # Set up a counter for the inner loop in block #4

	# Inner loop: subtract 1 from counter in block #4
	<
	-
]

# Move to the rightmost cell (block #2) and set up a counter for the multiplication loop
>>++++++

[
	# Outer loop: subtract 1 from counter in block #3
	>++++++++ # Set up a counter for the inner loop in block #4

	# Inner loop: subtract 1 from counter in block #4
	<
	-
]

# Move to the rightmost cell (block #2)
>

[
	# Subtract 1 from the counter in block #2 and move to the leftmost cell (block #1)
	-
	<<<<-

	# Inner loop: move to the rightmost cell (block #2)
	<-

	# Outer loop: move to the leftmost cell (block #1) and increment the value
	>>>>>
]

# Move back to the leftmost cell (block #1)
<<<<<

[
	# Outer loop: move to the rightmost cell (block #2)
	>

	[
		# Inner loop: increment block #1, block #2, and decrement block #3
		>+>>+<<<-
	]

	# Outer loop: move to the rightmost cell (block #2)
	>>>

	[
		# Inner loop: decrement block #2, increment block #3
		-
		<<<+
		>>>
	]

	# Outer loop: move back to the leftmost cell (block #1)
	<<<<-
]

# Move to the rightmost cell (block #2)
>>

[
	# Outer loop: subtract 1 from counter in block #3
	-
	>+
	<
]

# Print the result (block #2)
>.
