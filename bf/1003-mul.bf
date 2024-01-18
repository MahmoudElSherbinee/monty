>, >, <<  Set up three cells for input and temporary storage

+++++ +    Initialize the second cell with the value 5 (for ASCII '0')

[          Start a loop to read the first digit
  >----- ---  Subtract 48 to convert ASCII to numeric value
  >----- ---  Subtract 48 to convert ASCII to numeric value
  <<-        Move back to the first cell
]

>[         Start a loop to read the second digit
  >[>+>+<<-] Move to the third cell and duplicate the second digit
  [         Start a loop to subtract 48 from the second digit
    <+>-     Move to the second cell and subtract 1 from the second digit
  ]
  <<-        Move back to the first cell
]

>[-]>+     Subtract 1 from the first cell and add 1 to the third cell
>+++++ +++++  Set the fourth cell to 10 (for multiplication loop)

[          Start a loop to multiply the two digits
  -        Subtract 1 from the third cell (counter)
  >[       Start a loop to multiply the first digit
    >>>>    Move to the fifth cell (temporary storage)
    [      Start a loop to multiply the second digit
      <<<   Move back to the first cell
      [>>>] Multiply the second digit
      +     Move to the fifth cell and add the result
      >[<]  Move back to the second cell
    ]
    <<<<   Move back to the third cell (counter)
    <<<<   Move back to the first cell
  ]
  >>>>     Move to the fifth cell
  [<<<]    Multiply the first digit
  >>>>     Move to the sixth cell (temporary storage)
]

<-
<+++++ +++++  Move to the seventh cell (for printing)

>>>[-<<<->>>]<<<  Clear the fifth and sixth cells

<+++++ +    Initialize the eighth cell with the value 5 (for ASCII '0')

[          Start a loop to print the result
  >+++++ +++>  Move to the ninth cell and multiply the result by 10
  [+++++ +++>]  Move to the tenth cell and multiply the result by 10
  <[<]>-       Move back to the seventh cell and subtract 1
]

>>[.<<]<[<<]>>.  Print the result and newline
>>>>>>>>>>>>>>>>>>>>>>>++++++++++.  Additional characters (not part of the output)
