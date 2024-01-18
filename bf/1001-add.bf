# Read the first digit and convert it to its numeric value
,>, 

# Initialize a loop to subtract 48 from the ASCII code of the first digit ('0')
>++++++
[
    >++++++++
    <-
]

# Move to the second digit
>

# Subtract 48 from the ASCII code of the second digit ('0')
[
    -
    <<-
    >>
]

# Move back to the beginning of the data cells
<<

# Add the numeric values of the two digits
[
    -
    <+ 
    >
]

# Move to the cell containing the result
<

# Increment to get the ASCII code of the result
+

# Print the result
.
