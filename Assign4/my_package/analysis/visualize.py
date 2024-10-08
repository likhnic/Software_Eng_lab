#Imports
import matplotlib.pyplot as plt
import numpy as np
from PIL import ImageDraw, ImageFont 
import random

def plot_visualization(image, maskImage, pred_boxes, pred_masks, pred_class, pred_score, output_path, flag): # Write the required arguments

	# converting pred_masks into array
	pred_masks = np.array(pred_masks)

	z,_,h,w=pred_masks.shape
	new_masks = np.zeros((h,w))
	for k in range(min(z,3)):
		for i in range(h):
			for j in range(w):
				if pred_masks[k][0][i][j]>100/255:
					new_masks[i][j]=255

	#making a dictionary of predscore,pred_boxes,pred_class
	newdict = dict(zip(pred_score,zip(pred_boxes,pred_class)))
	dictitems = newdict.items()
	#sorting the dict to get top three scores(top 3 highest at last)
	sortedItems = sorted(dictitems)

	#loading pixels of the image which we want to mask 
	pixel_map = maskImage.load()

	#from top 3 highest scores, using pred_masks, changing the tint color of a particular region 
	#logic is to check whether a region in a box has any pixels which are white and coloring them(applying tint)
	if flag==0:

		for i in range(min(len(sortedItems),3)):
			#shape gives the bounding boxes (x1,y1) and (x2,y2)
			shape = (sortedItems[len(sortedItems)-1-i][1][0]) 
			#generating 3 random numbers in [0,1] to tint the pixels
			c1=random.random()/1.2
			c2=random.random()/1.2
			c3=random.random()/1.2
			# checking in the bounding box region for white pixels in pred_masks 
			for j in range(int(shape[0][1]),int(shape[1][1])):
				for k in range(int(shape[0][0]),int(shape[1][0])):
					# print(pred_masks[j][k],end=" ")
					if new_masks[j][k]>=150:
						#applying tint
						pixel_map[k,j]=(int(pixel_map[k,j][0]*c1),int(pixel_map[k,j][1]*c2),int(pixel_map[k,j][2]*c3))

	#using matplotlib making subplots and size (50,50)
	fig = plt.figure(figsize=(50, 50), dpi=23)
	#for drawing on maskImage

	if flag==1:
		draw = ImageDraw.Draw(maskImage)
		font = ImageFont.truetype("/home/likhith26090/Documents/projects/SoftEngLab/CS29006_SW_Lab_Spr2022-master/Python_DS_Assignment/my_package/analysis/arial.ttf", 12)

		for i in range(min(len(sortedItems),3)):

			shape = (sortedItems[len(sortedItems)-1-i][1][0]) 
			#drwaing rectangle with red border and a text (2 lines - line 1 for class and line 2 for score)
			draw.rectangle(shape,outline ="red")
			draw.multiline_text(sortedItems[len(sortedItems)-1-i][1][0][0], str(sortedItems[len(sortedItems)-1-i][1][1])+" "+str(sortedItems[len(sortedItems)-1-i][0]*10000//100), font=font,fill=(10, 255, 255, 255))

	#plotting actual image first
	subPlot = fig.add_subplot(1, 2, 1)
	#this is to remove the markers on x and y axis
	subPlot.set_xticks([])
	subPlot.set_yticks([])
	subPlot.imshow(image)
	#plotiing masked image
	subPlot = fig.add_subplot(1, 2, 2)
	subPlot.set_xticks([])
	subPlot.set_yticks([])
	subPlot.imshow(maskImage)
	#saving output in output_path
	fig.savefig(output_path, dpi=40, bbox_inches='tight')

    # The function should plot the predicted segmentation maps and the bounding boxes on the images and save them.
    # Tip: keep the dimensions of the output image less than 800 to avoid RAM crashes.