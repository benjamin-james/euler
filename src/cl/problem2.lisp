(defun problem2 (&optional (num 4000000))
  (let ((sum 0))
    (do ((left 1 right) (right 2 (+ right left)))
	((> right num))
      (if (evenp right)
	  (incf sum right)))
    (format t "The sum of all even Fibonacci numbers not exceeding ~r is ~d~%" num sum)))
