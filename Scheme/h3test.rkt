#lang racket
;LOTS OF COMMENTS -- hopefully your colorscheme doesn't have too gross
;of comment colors otherwise your eyes WILL bleed
(define image1
 (list
	    (list 0 1) (list 0 2)	     (list 0 4)
	    (list 1 1) (list 1 2)	     (list 1 4)	           (list 1 6)
 (list 2 0) (list 2 1) (list 2 2)	     (list 2 4) 	   (list 2 6)
	   				     (list 3 4) (list 3 5) (list 3 6) 
	    (list 4 1)
	    (list 5 1) (list 5 2) (list 5 3) (list 5 4) (list 5 5)
	    (list 6 1) (list 6 2) (list 6 3)
))
;;Original use was to copy image
;;Pass 2 images -- one to tail recurse
;;the other to be intact for isMember calls
;;
;(define (copy lst)
	;(cond ((empty? lst) '())
	   ;	(else (cons (car lst) (copy(cdr lst) )))))

;		(define editableimage (copy image1))

(define isMember 
	(lambda (xs1 xss2)
	(cond
		((null? xss2) #f)
		((equal? xs1 (car xss2)) #t)
		((not (equal? xs1 (car xss2)))
			(isMember xs1 (cdr xss2))))))



(define isAdjacent
	(lambda (xsn image1)
	   (cond
		[(isMember xsn image1) #t]
		(else #f))))

;;My attempt: find which of the 4 possible adjacents are
;;existing in the list. Recurse on each of those adjacents
;;and remove the list we are jumping to from the image
;;so the other functions don't consider it a possible move
(define possibleMoves
	;hold supposed to be "answer"
	(lambda (xs image1 hold)
		;list of surrounding possible points
	  (define vertDown (list (+ 1 (car xs)) (cadr xs))) 
	  (define vertUp (list (-  (car xs) 1) (cadr xs))) 
	  (define horzRight (list (car xs) (+ 1 (cadr xs)))) 
	  (define horzLeft (list (car xs) (- (cadr xs) 1))) 
	(remove xs image1)
	(define holder (cons xs hold))	
			;;Conditions to look for 4 surrounding points	
		 (cond((isAdjacent vertDown image1)
			(remove vertDown image1)
			(possibleMoves vertDown image1 holder)
			))
				;recursing on the VertUp and
				;horzLeft cause infinite loops?
				;Only the variables with - 1 defines
         	 (cond((isAdjacent vertUp image1)
			(remove vertUp image1)
			;(possibleMoves vertUp image1 holder)
			))

		 (cond((isAdjacent horzRight image1)
			(remove horzRight image1)
			(possibleMoves horzRight image1 holder)
			))

		 (cond((isAdjacent horzLeft image1)
			(remove horzLeft image1)
			;(possibleMoves vertUp image1 holder)
			))
			(display holder)))  ;Wanted to hold list
					    ;to hold all possibles
					    ;Too imperative? maybe

			
;;Wanted to define "answer" here. This would
;;later become the connectComponents
;;Would tail recurse on editable image
;;find not-isMember of "answer" and start there to
;;begin new adjacency matrix list	  
(possibleMoves (list 0 4) image1 '() )
(newline)

	








