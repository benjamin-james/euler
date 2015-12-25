(defun do-problem (path &optional (time-it nil))
  (if (load path)
      (let ((func (symbol-function (find-symbol (string-upcase (string-right-trim ".lisp" (enough-namestring path)))))))
	(if time-it
	    (time (funcall func))
	    (funcall func)))))

(defun do-all-problems (&optional (time-it nil))
  (dolist (p (directory "problem*.lisp"))
    (do-problem p time-it)))
