(defun palindrome-p (num)
  (let ((str (format nil "~a" num)))
    (string= str (reverse str))))

(defun problem4 ()
  (let ((largest 0))
    (dotimes (i 999)
      (dotimes (j 999)
	(let ((product (* i j)))
	  (if (and (> product largest)
		   (palindrome-p product))
	      (setf largest product)))))
    (format t "The largest palindrome made from the product of two 3 digit numbers is ~d~%" largest)))

