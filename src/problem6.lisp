
(defun problem6 (&optional (limit 100))
  (let ((sum 0) (squares 0))
    (dotimes (i limit)
      (incf sum (+ i 1))
      (incf squares (* (+ i 1) (+ i 1))))
    (format t "~d" (- (* sum sum) squares))))


