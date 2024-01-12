####### REQUIRED IMPORTS FROM THE PREVIOUS ASSIGNMENT #######
from logging import root
from my_package.model import InstanceSegmentationModel
from my_package.data import Dataset
from my_package.analysis import plot_visualization
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage

####### ADD THE ADDITIONAL IMPORTS FOR THIS ASSIGNMENT HERE #######
from functools import *
import numpy as np
from PIL import Image
from tkinter import Tk,END,StringVar,Entry,Button
from tkinter import GROOVE, Label, PhotoImage, filedialog
from tkinter.ttk import Combobox
# Define the function you want to call when the filebrowser button is clicked.
def fileClick(clicked, dataset, segmentor):

	####### CODE REQUIRED (START) #######
	# This function should pop-up a dialog for the user to select an input image file.
	# Once the image is selected by the user, it should automatically get the corresponding outputs from the segmentor.
	# Hint: Call the segmentor from here, then compute the output images from using the `plot_visualization` function and save it as an image.
	# Once the output is computed it should be shown automatically based on choice the dropdown button is at.
	# To have a better clarity, please check out the sample video.
	filename =  filedialog.askopenfilename(initialdir = dataset.path,title = "Select a JPG file",filetypes = (("jpeg files","*.jpg"),("all files","*.*")))
	if not filename:
		return	
	for i in range(len(filename)):
		if filename[i+2:i+5]=="jpg":
			ind=int(filename[i])
	imageDict=dataset[ind]
	# input image is the image which is to be fed into segementor
	inputImage = imageDict['image'][0]
	#maskImage is the image where we will show top 3 boxes on image, as it is in [0,1], we will
	#convert it back to normal image by multiplying 255 and making it h,w,3 from 3,h,w
	maskImage = imageDict['image'][0]
	maskImage = maskImage.transpose(1,2,0)
	maskImage = maskImage*255
	maskImage = Image.fromarray(maskImage.astype(np.uint8))
	#actual image is the image which we use to compare in subplot
	actualImg = maskImage.copy()
	#getting output from segmentor
	pred_boxes, pred_masks, pred_class, pred_score = segmentor(inputImage)
	#setting clicked value to pat so that usage of globa variables can be reduced
	clicked.set("../../"+dataset.path+"tranformation"+str(ind))
	path0 = "../../"+dataset.path+"tranformationSegmentation.png"
	path1 = "../../"+dataset.path+"tranformationBounding-box.png"

	#passing all the parameters to the visualisation function
	plot_visualization(actualImg,maskImage,pred_boxes, pred_masks, pred_class, pred_score, path0,0)
	maskImage = actualImg.copy()
	plot_visualization(actualImg,maskImage,pred_boxes, pred_masks, pred_class, pred_score, path1,1)
	####### CODE REQUIRED (END) #######

# `process` function definition starts from here.
# will process the output when clicked.
def process(clicked):

	####### CODE REQUIRED (START) #######
	# Should show the corresponding segmentation or bounding boxes over the input image wrt the choice provided.
	# Note: this function will just show the output, which should have been already computed in the `fileClick` function above.
	# Note: also you should handle the case if the user clicks on the `Process` button without selecting any image file.
	if clicked.get()=="Segmentation":
		print("Please open a file to process")
		return

	e.delete(0,END)
	e.insert(0,"Image-"+clicked.get()[-1])
	choice="Segmentation"
	if drop.current()==1:
		choice="Bounding-box"

	photo = PhotoImage(file=clicked.get()[:-1]+choice+".png")
	label.configure(image=photo)
	label.image = photo
	####### CODE REQUIRED (END) #######
	
# `main` function definition starts from here.
if __name__ == '__main__':

	####### CODE REQUIRED (START) ####### (2 lines)
	# Instantiate the root window.
	# Provide a title to the root window.
	root=Tk()
	root.title("Image Viewer")
	####### CODE REQUIRED (END) #######
	# Setting up the segmentor model.
	annotation_file = './data/annotations.jsonl'
	# transforms = [RotateImage(10),RotateImage(90)]
	transforms = []
	# Instantiate the segmentor model.
	segmentor = InstanceSegmentationModel()
	# Instantiate the dataset.
	dataset = Dataset(annotation_file, transforms=transforms)

	# Declare the options.
	options = ["Segmentation", "Bounding-box"]
	clicked = StringVar()
	clicked.set(options[0])

	e = Entry(root, width=70)
	e.grid(row=0, column=0)

	####### CODE REQUIRED (START) #######
	# Declare the file browsing button
	filebrowse = Button(root,text="Browse", pady=5,activeforeground="blue",relief=GROOVE,command=partial(fileClick,clicked,dataset,segmentor))
	filebrowse.grid(row=0,column=1)
	####### CODE REQUIRED (END) #######

	####### CODE REQUIRED (START) #######
	# Declare the drop-down button
	drop=Combobox(root, textvariable=options)
	drop['values']=options
	drop.current(0)
	drop.grid(row=0,column=2)
	label = Label(image="")
	label.grid(row=1,column=0,columnspan=4)
	####### CODE REQUIRED (END) #######

	# This is a `Process` button, check out the sample video to know about its functionality
	myButton = Button(root, text="Process", pady=5,activeforeground="blue",relief=GROOVE, command=partial(process, clicked))
	myButton.grid(row=0, column=3)

	####### CODE REQUIRED (START) ####### (1 line)
	# Execute with mainloop()
	root.mainloop()
	####### CODE REQUIRED (END) #######




	# for i in range(len(transforms)):
	# 	flag=0
	# 	if clicked.get()=="Bounding-box":
	# 		clicked.set("Bounding-box")
	# 		flag=1
	# 	# input image is the image which is to be fed into segementor
	# 	inputImage = imageDict['image'][i]
	# 	#maskImage is the image where we will show top 3 boxes on image, as it is in [0,1], we will
	# 	#convert it back to normal image by multiplying 255 and making it h,w,3 from 3,h,w
	# 	maskImage = imageDict['image'][i]
	# 	maskImage = maskImage.transpose(1,2,0)
	# 	maskImage = maskImage*255
	# 	maskImage = Image.fromarray(maskImage.astype(np.uint8))
	# 	#actual image is the image which we use to compare in subplot
	# 	actualImg = imageDict['image'][i]
	# 	actualImg = actualImg.transpose(1,2,0)
	# 	actualImg = actualImg*255
	# 	actualImg = Image.fromarray(actualImg.astype(np.uint8))
	# 	#getting output from segmentor
	# 	pred_boxes, pred_masks, pred_class, pred_score = segmentor(inputImage)
		
	# 	clicked.set("../../"+dataset.path+"tranformation")
	# 	path0 = "../../"+dataset.path+"tranformationSegmentation.png"
	# 	path1 = "../../"+dataset.path+"tranformationBounding-box.png"

	# 	#passing all the parameters to the visualisation function
	# 	plot_visualization(actualImg,maskImage,pred_boxes, pred_masks, pred_class, pred_score, path0,0,None)
	# 	maskImage = imageDict['image'][i]
	# 	maskImage = maskImage.transpose(1,2,0)
	# 	maskImage = maskImage*255
	# 	maskImage = Image.fromarray(maskImage.astype(np.uint8))
	# 	plot_visualization(actualImg,maskImage,pred_boxes, pred_masks, pred_class, pred_score, path1,1,None)