(defun problem1 (&optional (num 1000))
  (let ((sum 0))
    (dotimes (i num)
      (if (or
	   (zerop (mod i 5))
	   (zerop (mod i 3)))
	  (incf sum i)))
      (format t "The sum of all multiples of 3 or 5 below ~d is ~d~%" num sum)))
