function Y = seededRegionGrowing(filename,seed_x,seed_y,T)
% This function performs " seeded region growing" in an image from a 
% specified seedpoint (x,y)
%
% J = seededRegionGrowing(filename,seed_x,seed_y,T) 
% 
% filename : input image filename
% Y : number of pixels in the region
% seed_x,seed_y : the position of the seedpoint
% T : threshold criterion
%
% The region is iteratively grown by comparing all unallocated 8-neighbouring 
% pixels to the region.The difference between a pixel's intensity value  
% and the region's mean,is used as a measure of similarity. The pixel with 
% the smallest difference measured this way is allocated to the respective  
% region. 
%
% Example:
% Y = regiongrowing('img1.bmp',159,120,5); 
% Author: Kushal Jagadeesha, MSRSAS, Conventry University. 

% filename = 'img2.bmp';
% seed_x = 185;
% seed_y = 332;
% T = 20;
tic();
I1 = imread(filename);

I = medfilt2(I1,[3 3]);

I = double(I);
[h w] = size(I);
flagArr = double(ones(h,w)*255);%create a buffer to check if seed pixel is added or not
%8-connectivity neighbourhood
neigb = [-1 -1; 
         -1  0;
         -1  1;
          1 -1;
          1  0;
          1  1;
          0 -1;
          0  1];
x = seed_x;
y = seed_y;

%Start region growing. if pixel meets the threshold criterion add it to the
%region
no_of_pixels = 1;
pixel_arr = zeros(w*h,3);
pixel_arr(no_of_pixels,:) = [x y I(y,x)];
flagArr(y,x) = 0;
M = I(y,x);
count = 0;
sum_segmented_pixels = I(y,x);
while(count<no_of_pixels)
    for j=1:8
        %take the neighborhood
        xn= pixel_arr(count+1,1) + neigb(j,1);
        yn = pixel_arr(count+1,2) + neigb(j,2);
        %image boundary check
        flag = (xn>=1)&&(yn>=1)&&(xn<w)&&(yn<h);
        if (flag)
            %check threshold criterion
            diff = abs(I(yn,xn) - M);
            if((diff<T) && (flagArr(yn,xn) == 255))
                no_of_pixels = no_of_pixels+1;
                pixel_arr(no_of_pixels,:) = [xn yn I(yn,xn)];
                flagArr(yn,xn) = 0;
                sum_segmented_pixels = sum_segmented_pixels + I(yn,xn);
            end
        end 
    end
    M = sum_segmented_pixels / no_of_pixels;
    count = count+1;
end
%figure;

Y = flagArr;
toc()
fprintf('Region grown area = %d pixels\n',no_of_pixels+1); 
%imshow(uint8(I));
figure;imshow(uint8(flagArr));
end